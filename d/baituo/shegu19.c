//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "蛇谷坡地");
	set("long", @LONG
这里已经是蛇谷的另一端，山势起伏较大，西南边是一片树林，
往北则是乱石嶙峋的山崖。
LONG
	);

	set("exits", ([ 
	    "northup" : __DIR__"shegu_shanya",
	    "southwest" : __DIR__"shegu18",
	]));

	set("objects", ([
	    "/d/baituo/npc/bt_snake" : 2,
	]));

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
