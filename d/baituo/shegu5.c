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
曲折起伏，蜿蜒难行。山路两旁林木葱郁，草丛中不时响起沙沙之声
，似乎有什麽在草里来回窜动。西北边的树木似乎比较稀少。
LONG
	);

	set("exits", ([ 
	    "southeast" : __DIR__"shegu4",
	    "northwest" : __DIR__"shegu6",
	]));

	set("objects", ([
	    "/d/city/obj/branch2" : 1,
	    "/d/city/npc/maque" : 2,
	]));

	set("hide_snake", random(3));
	set("grass", 1);

	set("cost", 3);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
