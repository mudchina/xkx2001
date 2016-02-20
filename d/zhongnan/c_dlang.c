//Cracked by Roath
///d/zhongnan/c_dlang.c 东练功场
// sdong: 07/23/98

inherit ROOM;

int do_hit(string arg);

void create()
{
		  set("short", "练功场");
		  set("long", @LONG
这里是重阳宫的练功场，地上铺着青砖。练功场吊着几个沙袋(shadai)。
有几个小道士正在练功。往西是广场。
LONG
		  );
		  set("exits", ([
					 "west" : __DIR__"guangchang",
					 "south": __DIR__"donglang",
		  ]));


		  set("outdoors", "zhongnan" );

		  set("valid_startroom", 1);

		  set("cost", 1);
		  set("item_desc",([
				"shadai" : "这是一个大沙袋，看起来非常结实。好象是用来练拳法的，你可以打打看(da shadai)。\n",
		  ]));

		  setup();
}

void init()
{
//		  ::init();
		  add_action("do_hit", "da");
}


int do_hit(string arg)
{       object me = this_player();
		  int check;
		  if ( !arg )
					 return notify_fail( "你想击什麽?\n");
		  if ( arg != "shadai" )
					 return notify_fail( "你想击什麽?\n");


		if ((int)me->query("qi") < 26 || me->query("jingli") < 30 )
					 return notify_fail("你累的半死，心有余而力不足，手都抬不起来了。\n");
		  me->receive_damage("qi", 25);
		  me->receive_damage("jingli", 25);

		  message_vision("$N握拳狠狠地击向沙袋，觉得拳头微微有些痛。\n", me);

		  check = (int)me->query_skill("cuff",1)*(int)me->query_skill("cuff",1)*(int)me->query_skill("strike",1);
		  if (check > (int)me->query("combat_exp") * 10)
		  {       write ("你打了一会，发现自己没有什么进步，看来该去弄点实战经验了。\n");
					 return 1;
		  }

		  if ((int)me->query_skill("cuff", 1) >= 101)
		  {       write("你打了一会，发现毫无收获。\n");
					 return 1;
		  }

		  me->improve_skill("cuff", me->query("int")+me->query("con") );
		  return 1;
}
