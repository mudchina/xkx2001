//Cracked by Roath
// road: /zhongnan/taiyici3.c
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
山光水影，风景贻人。这里原来是太乙池的西岸，太累的话，你可以爬(climb)
上岸。远远望去，东边的岸上有一条小路通往终南山主峰。想不想游(swim)过
去看？
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
		return notify_fail("你已经在西岸了。\n");
	}
	else if (arg == "east")
	{
		message_vision( HIY"\n$N在太乙池中划了划水，往东游了起来。\n"NOR, me);
		me->move("/d/zhongnan/taiyici2");
		message_vision( HIY"\n$N游了过来。\n"NOR, me);
		return 1;
	}

	message_vision( HIY"\n$N在太乙池中划了划水，用力游了起来。\n"NOR, me);
	return 1;
}

int do_climb(string arg)
{
	object me = this_player();

	if(me->is_busy())
		return notify_fail("你还在忙着呢。\n");
	if(arg == "up" || arg=="west" )
	{
		message_vision( HIY"\n$N在太乙池中往岸上爬了上去。\n"NOR, me);
		me->move("/d/zhongnan/hubing");
		message_vision( HIY"\n$N从太乙池中爬了上来。\n"NOR, me);
		return 1;
	}

	return notify_fail("那个方向没法爬。\n");
}
