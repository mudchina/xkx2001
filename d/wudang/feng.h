//Cracked by Roath
// feng.h 
// by Marz 

#include <ansi.h>

int look_feng(string arg);

int look_feng(string arg)
{
	int lucky;
	object me;

	if( !arg || arg!="feng" ) return 0;
	write("

                      ^
                     ^ ^
                   @@@__^    
                    ^ @@@__
                   ^   ^  ^

抬眼望去，流云片片，烟雾缭绕，天柱峰若隐若现，似遥不可既…\n\n");

	me = this_player();
	lucky = random(me->query_dex() + me->query_kar()) + me->query_dex();

	if (lucky > 58)
	{
		write("突然间，有个黑点在云雾中一掠而过，好象是一只大雕！\n"
			+"可是那么高的地方，怎么可能呢？ｈｍｍ．．．也许是一时花了眼。\n\n");
	
	}else if(lucky >= 45)
	{
		// do nothing here
	}else if(lucky >= 30)
	{
		message_vision(HIY"$N光顾着看天，一不留神脚下踏了个空，... 啊...！\n\n"NOR, me);
		message_vision(HIY"$N一个趔趄摔了一跤！还好，只伤了些皮骨，没有滚下去。\n\n"NOR, me);
		me->receive_damage("qi", 30+4*random((int)me->query("age")));
		me->receive_damage("jing", 50);
	}else // bad luck 
	{
		message_vision(HIR"$N光顾着抬头看天，一不留神脚下踏了个空，... 啊...！\n\n"NOR, me);
		tell_object(me, HIR"你控制不住地直往山下滚，只觉得浑身无处不疼，痛得要晕死过去。\n\n"NOR);
		me->move(__DIR__"tyroad8");
		message("vision", HIR"只见" + me->query("name")
			+ "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n\n"NOR,
			environment(me), me);
		me->unconcious();
	}
	
	return 1;
}
