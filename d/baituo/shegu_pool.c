//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "水池");
	set("long", @LONG
一潭清澈的池水，由蛇谷山麓间的流水积蓄而成，是谷中动物的
重要水源，许多飞禽走兽都在这里饮水。
LONG
	);

	set("exits", ([ 
	    "south" : __DIR__"shegu12",
	]));

	set("hide_snake", random(3));

	set("resource/water",1);
	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

#include "snake_room.h"
