//Cracked by Roath
// qiaobi1.c 峭壁１
// qfy July 13, 1996

inherit ROOM;

void create()
{
        set("short", "峭壁");
        set("long", @LONG
你攀在峭壁上稍作休息。抬头一望，估略尚有十余丈方能到达峭壁上
的平台，心里不禁筹躇着应否继续往上爬。
LONG
        );

	set("cost", 6);
        setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me = this_player();

	if ( !arg )
	   return notify_fail( "什么？\n" );

	if ( arg == "down" ) {
	   message_vision("$N手足并用，小心翼翼地往峭壁下爬去。\n", me);
	   me->move(__DIR__"qiaobi0");
	   message("vision", me->name()+"由峭壁上爬了下来。\n", environment(me), me);
	   write("你双脚踏上实地，不由得透了一口大气。\n");
	}
	else if ( arg == "up" ) {
	   if ( (int)me->query_skill("dodge") <= 100 ) {
	      	message_vision("$N勉力再纵身跃起，但轻功火侯未够，上不了平台。\n", me);
	   	message_vision("结果$N差点儿失手摔下峭壁，虽能及时扳着石壁，但已受了几处伤。\n", me);
	   	me->add("eff_qi", -5000/(int)me->query_skill("dodge"));
	   }
	   else {
		message_vision("$N深吸一口气纵身跃起，几个起落间，已窜上了平台。\n", me);
		me->receive_damage("qi", 10000/(int)me->query_skill("dodge"));
		write("你只觉得气喘嘘嘘，心跳加速，还是先休息一阵吧。\n\n");
		me->move(__DIR__"pingtai");
	   }
	}
	else return notify_fail( "你只能往上或往下爬！\n" );

	return 1;
}
