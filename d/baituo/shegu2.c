//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "蛇谷山道");
	set("long", @LONG
这是白驼山蛇谷中的山路，是一条人马踩出来的小道，随着地势
曲折起伏，蜿蜒难行。
LONG
	);

	set("exits", ([ 
	    "southup" : __DIR__"shegu1",
	    "northwest" : __DIR__"shegu3",
	]));

	set("cost", 5);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	this_player()->set("enter_shegu", 1);
}

int valid_leave(object me, string dir)
{
	object room;
	int i, w;

	room = load_object("/d/baituo/shegu1");

	if (dir == "southup") {
		if ( !me->query("baituo/shegu_permit") && room->query("defense") )
			return notify_fail("你想走出蛇谷，但是谷口红雾弥漫，你一走近，便觉腥臭扑鼻，感觉竟有些晕眩。\n看来这是极为厉害的毒雾，难以强行通过。\n");
	}
	return ::valid_leave(me,dir);
}
