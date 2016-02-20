//Cracked by Roath
// xiakedao/shanxia.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "山脚下");
        set("long", @LONG
山脚下是一块平地，四周摆了几个木桩(muzhuang)。这里好象是个
练武场，有一位少年正在练功。几根树枝从头顶上小山凹中垂了下来。
LONG );

      set("exits", ([
		     "north":__DIR__"xiaolu3",
		     "west" : __DIR__"caodi",
		     "southup"  : __DIR__"shanlu4",
      ]));
	set("item_desc",([
	    "muzhuang" : "这是一根六尺高的木桩，中间裹着厚厚的牛皮纸。这是用来练掌
法的，你可以打打看(strike muzhuang)。\n",
	]));
	set("objects", ([ 
		       __DIR__ + "npc/taohua" : 1,
      ]));
	
	set("outdoors", "xiakedao" );
	set("cost", 2);
	setup();
}

void init()
{
        ::init();
	add_action("do_strike", "strike");
	add_action("do_jump", "jump");
}
/*
int do_play(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "你想玩什麽?\n");
	if ( arg != "shiqiu" )
		return notify_fail( "那有什麽好玩的。 play shiqiu 吧。\n");

	check = (int)me->query_skill("parry",1)*(int)me->query_skill("parry",1)*(int)me->query_skill("parry",1);
	if (check > (int)me->query("combat_exp") * 10)
	{	write ("你实战经验不足，无法领悟。\n");
		return 1;
	}

      if ((int)me->query("qi") < 30)
		return notify_fail("没力气，抱不起那石球。\n");
	me->receive_damage("qi", 20);

	message_vision("$N抱起一个石球，把石球在手中转来转去的玩。\n", me);
	if ((int)me->query_skill("parry", 1) >= 30)
	{	write("你玩了一会儿精疲力尽，却无法领悟出什麽。\n");
		return 1;
	}

	me->improve_skill("parry", me->query("int"));
	return 1;
}
*/

int do_strike(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "你想击什麽?\n");
	if ( arg != "muzhuang" )
		return notify_fail( "老老实实击木桩吧。\n");

	check = (int)me->query_skill("strike",1)*(int)me->query_skill("strike",1)*(int)me->query_skill("strike",1);
	if (check > (int)me->query("combat_exp") * 10)
	{	write ("你实战经验不足，无法领悟。\n");
		return 1;
	}

      if ((int)me->query("qi") < 30)
		return notify_fail("你累的连站都站不起来了，怎麽击木桩。\n");
	me->receive_damage("qi", 20);

	message_vision("$N站了一个马步，挥掌击向木桩。\n", me);
	if ((int)me->query_skill("strike", 1) >= 30)
	{	write("你打了一会，发现已经无法领悟出什麽东西了。\n");
		return 1;
	}

//	write("击打着木桩你领悟了几个基本掌法中的难题。\n");
	me->improve_skill("strike", me->query("int"));
	return 1;
}
int do_jump(string arg)
{	object me = this_player();
	if ( !arg )
		return 0;
	if ( arg != "up" )
		return 0;
	if (me->query_skill("dodge") > 20) 
	{	message_vision("$N一纵身，拉着从山坡上垂下的树枝爬了上去。\n", me);
		me->move(__DIR__"shibi");
		message("vision", me->name() + "从山脚下爬了上来。\n",environment(me), me );
	}
	else
		message_vision("$N跳起来却够不着垂着的树枝。\n", me);
	return 1;
}
