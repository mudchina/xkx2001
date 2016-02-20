//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "蛇谷树林");
	set("long", @LONG
这是白驼山的蛇谷之中，林木葱郁，四下一片静谧。
LONG
	);

	set("exits", ([ 
	    "north" : __DIR__"shegu26",
	    "southwest" : __DIR__"shegu_maze4",
	]));

	set("cost", 1);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

void init()
{
	this_player()->set("enter_shegu", 1);
}
