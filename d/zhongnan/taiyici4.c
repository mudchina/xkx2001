//Cracked by Roath
// road: /zhongnan/taiyici4.c
// by sdong 08/98

#include <ansi.h>
inherit ROOM;

int do_climb(string arg);
int do_swim(string arg);
int do_study(string arg);
int do_practice(string arg);
int do_exercise(string arg);

void create()
{
		  set("short",HIC"太乙池"NOR);
		  set("long",@LONG
你身在湖水里，只觉得湖水冰凉透骨。但见四周高峰环列，池面碧波荡漾，
山光水影，风景贻人。东边的岸上有条小路可以上山。往西望去，西边的山峰
之间似乎有一个大洞。
LONG);


		  set("resource/water", 1);


		  set("no_clean_up", 0);

	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
	add_action("do_swim", "swim");
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
		  tell_object(me, "这么深的水，踩都踩不到底，怎么练功啊？\n");
		  return 1;
}

int do_practice(string arg)
{
		  object me = this_player();
		  tell_object(me, "这么深的水，踩都踩不到底，怎么练功啊？\n");
		  return 1;
}

int do_study(string arg)
{
		  object me = this_player();
		  tell_object(me, "这么深的水，踩都踩不到底，怎么读书啊？\n");
		  return 1;
}


int do_swim(string arg)
{
	object me = this_player();
	int cost;

	if(me->is_busy())
		return notify_fail("你还在忙着呢。\n");
	cost = (200-me->query_skill("swimming",1))/10;
	if ( cost<3 )cost = 3;
	me->add("jingli",-cost);
	me->improve_skill( "swimming",random( me->query("con",1)/2 ) );
	me->start_busy(random(3));

	if (arg == "west")
	{
		message_vision( HIY"\n$N在太乙池中划了划水，往西游了起来。\n"NOR, me);
		if(me->query_temp("tyc/east") <= 0)
		{
			me->move("/d/zhongnan/taiyici1");
			message_vision( HIY"\n$N游了过来。\n"NOR, me);
			return 1;
		}
		me->add_temp("tyc/east",-1);
		return 1;
	}
	else if (arg == "east")
	{
		message_vision( HIY"\n$N在太乙池中划了划水，往东游了起来。\n"NOR, me);
		if(me->query_temp("tyc/east") >= 5)
		{
			me->move("/d/zhongnan/taiyici3");
			message_vision( HIY"\n$N游了过来。\n"NOR, me);
			return 1;
		}
		me->add_temp("tyc/east",1);
		return 1;
	}

	message_vision( HIY"\n$N在太乙池中划了划水，用力游了起来。\n"NOR, me);
	return 1;
}
