//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;
string look_bush();

void create()
{
	set("short", "蛇谷树林");
	set("long", @LONG
这是白驼山的蛇谷之中，四周生长着丛丛矮树(bush)，满地都是
杂草和枯枝败叶，气味不大好闻。小路曲折地穿过树丛，不知道通往
哪里。
LONG
	);

	set("exits", ([ 
	    "northwest" : __DIR__"shegu15",
	    "southwest" : __DIR__"shegu29",
	]));

	set("item_desc", ([
	"bush" : (: look_bush :),
	]));

	set("objects", ([
	    "/d/city/obj/branch"+(1+random(4)) : 1,
	]));

	set("hide_snake", random(3));
	set("grass", 1);
	set("bush", 1);

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
