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
	    "southeast" : __DIR__"shegu2",
	    "northeast" : __DIR__"shegu4",
	]));

	set("cost", 3);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	this_player()->set("enter_shegu", 1);
}
