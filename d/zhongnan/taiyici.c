//Cracked by Roath
// road: /zhongnan/taiyici.c
// by sdong 08/98

#include <ansi.h>
inherit ROOM;

int do_jump();

void create()
{
		  set("short",HIC"太乙池"NOR);
		  set("long",@LONG
你眼前出现一个山间湖泊，这就是著名的太乙池(chi)，传为唐天宝年间地震造成，
四周高峰环列，池面碧波荡漾，山光水影，风景十分优美。
LONG);

		  set("exits",([
							  "southup" : __DIR__"shanlu15",
							 ])
			  );

		  set("resource/water", 1);

		  set("item_desc", ([
		"chi" :
"\n\n这是一个很大的山间湖，碧波荡漾，湖水清澈见底，让人忍不住想跳(jump)下去\n"
"畅游一番。\n\n\n",
])  ) ;

		  set("no_clean_up", 0);

	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump()
{
	object me = this_player();

	if ( me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	message_vision(HIY"\n$N往太乙池中跳去。\n"NOR, me);
	me->set_temp("taiyi_swimming", 1);
	me->move("/d/zhongnan/taiyici1");
	message_vision(HIY"\n$N往太乙池中跳了进来。\n"NOR, me);

	return 1;
}

