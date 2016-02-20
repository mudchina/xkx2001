//Cracked by Roath
///d/zhongnan/c_xilang.c 西练功场
// sdong: 07/23/98

inherit ROOM;

void create()
{
		  set("short", "练功场");
		  set("long", @LONG
这里是重阳宫的练功场，地上铺着青砖。中央立着几个木头人(mutouren)。
有几个小道士正在练功。往东是广场。
LONG
		  );
		  set("exits", ([
					 "east" : __DIR__"guangchang",
					 "south" : __DIR__"xilang",
		  ]));


		  set("outdoors", "zhongnan" );

		  set("valid_startroom", 1);

		  set("cost", 1);
		  set("item_desc",([
				"mutouren" : "这是一个六尺高的木头人，形状大小犹如一位真人。全身裹着厚厚的牛皮纸。好象是用来练掌法的，你可以打打看(strike mutouren)。\n",
		  ]));

		  setup();
}

void init()
{
//		  ::init();
		  add_action("do_strike", "strike");
}


int do_strike(string arg)
{       object me = this_player();
		  int check;
		  if ( !arg )
					 return notify_fail( "你想击什麽?\n");
		  if ( arg != "mutouren" )
					 return notify_fail( "你想击什麽?\n");


		if ((int)me->query("qi") < 30 || me->query("jingli") < 30 )
					 return notify_fail("你累的半死，心有余而力不足，手掌都抬不起来了。\n");
		  me->receive_damage("qi", 25);
		  me->receive_damage("jingli", 25);

		  message_vision("$N蹲了一个马步，挥掌击向木头人。\n", me);

		  check = (int)me->query_skill("strike",1)*(int)me->query_skill("strike",1)*(int)me->query_skill("strike",1);
		  if (check > (int)me->query("combat_exp") * 10)
		  {       write ("你打了一会，发现自己没有什么进步，看来该去弄点实战经验了。\n");
					 return 1;
		  }

		  if ((int)me->query_skill("strike", 1) >= 101)
		  {       write("你打了一会，发现毫无收获。\n");
					 return 1;
		  }

		  me->improve_skill("strike", me->query("int")+me->query("con") );
		  return 1;
}

