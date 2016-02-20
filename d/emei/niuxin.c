//Cracked by Roath
// niuxin.c 牛心石
// haowen 10/10/00 add busy check in jump
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "牛心石");
	set("long", @LONG
你落脚处乃是块黑褐色的巨石，黑龙白龙二江在此和流。水拍牛心，
浪花飞溅，声震山谷。你立于此，眼望两江之水从脚下奔腾而过，不由心
魂飞荡，两腿发软，不可自持。
LONG
	);

        set("outdoors", "emei" );
	set("cost", 2);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_dazuo", "dazuo");
}

int do_jump(string arg)
{
	object me = this_player();
	if ( !arg || (arg != "back" && arg != "bank" ) )
		return 0;
	if(me->is_busy())
		{
             	tell_object(me,"你现在正忙着呢！\n");    
		return 0;
		}
	message_vision("$N猛提一口气，一纵身向岸边跳去。\n", me);
	me->move(__DIR__"qingyin");
	message("vision", me->name() + "猛提一口气，从牛心石上跳了回来。\n",
		environment(me), ({me}) );
	
	return 1;
}

int do_dazuo(string arg)
{
	object me, where;
	string force_skill;
	int exercise_cost, level;
	me = this_player();
	where = environment(me);
	seteuid(geteuid(me));

	if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能练内功，会走火入魔。\n");

        if( !stringp(force_skill = me->query_skill_mapped("force")) )
                return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

        if( !arg || !sscanf(arg, "%d", exercise_cost))
                return notify_fail("你要花多少气练功？\n");
        if (exercise_cost < 10)
                return notify_fail("你的内功还没有达到那个境界！\n");

        if( (int)me->query("qi") < exercise_cost )
                return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
                return notify_fail("你现在精不够，无法控制内息的流动！\n");

	level = me->query_skill("linji-zhuang", 1);

	if ( force_skill == "linji-zhuang" 
	  && level >= 30 && level < 105 
	  && me->query("combat_exp") > level*level*level/10 
	  && SKILL_D(force_skill)->valid_learn(me) ) {
		me->improve_skill("linji-zhuang", 
			random(me->query_int()+me->query_con()) );
		me->add("jing", -20-random(20));
		tell_object(me, HIY"此处打坐，正暗合十二庄修行之动静相辅要旨，惊涛骇浪声中，\n你对「临济十二庄」有所领悟。\n"NOR);
	}
	return 0;
}
