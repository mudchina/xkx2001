//Cracked by Roath
// road: /zhongnan/xuanya2.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
int do_climb(string arg);
int do_exercise(string arg);
int do_practice(string arg);
int do_study(string arg);

void create()
{
		  set("short",HIC"悬崖"NOR);

		  set("long",@LONG
你攀在悬崖上，悬崖四面都是险岩怪石，越往上就越难攀，四面光溜溜的崖陡
如壁，寸草不生。望下一瞧，只吓得魂飞魄散。原来上来时一步步的硬挺，想从原
路下去时，本来的落脚之点已给凸出的岩石挡住，再也摸索不到，若是涌身向下一
跳，势必碰在山石上撞死。几只巨大的黑雕盘旋在空中。
LONG);

	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_exercise",  "exercise");
	add_action("do_exercise",  "dazuo");
	add_action("do_exercise",  "respirate");
	add_action("do_exercise",  "tuna");
	add_action("do_practice",  "practice");
	add_action("do_practice",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
}

int do_exercise(string arg)
{
		  object me = this_player();
		  tell_object(me, "你爬在悬崖上，手脚并用，都觉得吃力，哪能腾出手来练功啊？\n");
		  return 1;
}

int do_practice(string arg)
{
		  object me = this_player();
		  tell_object(me, "你爬在悬崖上，手脚并用，都觉得吃力，哪能腾出手来练功啊？\n");
		  return 1;
}

int do_study(string arg)
{
		  object me = this_player();
		  tell_object(me, "你爬在悬崖上，手脚并用，都觉得吃力，哪能腾出手来读书啊？\n");
		  return 1;
}

int do_climb(string arg)
{
	object me = this_player();
	int gain,cost;

	if(me->is_busy())
		return notify_fail("你还在忙着呢。\n");

	if(me->query_skill("dodge") < 90 && arg == "up" )
		return notify_fail("四面光溜溜的崖陡如壁，你轻功不够，怎么也爬不上去。\n");

	cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
	if ( cost<10 )cost = 10;
	cost *= 2;

	if( me->query("jingli") < 30)
		return notify_fail("你累的实在爬不动了。\n");

	me->add("jingli",-cost);

	if( arg != "up" && arg != "down" )
		return notify_fail("那个方向没法爬。\n");

	gain = me->query("con",1)*2;
	gain *= 2;

	if ( me->query_skill("dodge") > 300 ) gain /= 2;

	me->improve_skill( "dodge",gain/2+random( gain ) );

	if( me->query_skill( "jinyangong",1) > 0 )
		me->improve_skill( "jinyangong",random( gain ) );



	if(arg == "up" )
	{
		message_vision( HIY"\n$N在悬崖上攀藤附葛，一步步的爬上去。\n"NOR, me);
		me->move("/d/zhongnan/xuanya3");
		message_vision( HIY"\n$N爬了上来。\n"NOR, me);
		me->improve_skill( "dodge",(gain+random( gain ))/2 );
		me->add("jingli",-cost);
		me->start_busy( 1 );
		return 1;
	}
	else if(arg == "down" )
	{
		message_vision( HIY"\n$N在悬崖上攀藤附葛，小心谨慎的爬下去。\n"NOR, me);
		me->move("/d/zhongnan/xuanya1");
		message_vision( HIY"\n$N爬了下来。\n"NOR, me);
		return 1;
	}

	return notify_fail("那个方向没法爬。\n");
}
