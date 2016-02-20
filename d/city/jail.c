//Cracked by Roath
// Room: /city/bingqiku.c
// YZC 1995/12/04 
//Jay 2/4/97

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "监狱");
	set("long", @LONG
这里是监狱，约莫两丈见方的一间大石室，墙壁和顶板都是大石所砌。
墙角里放着一只粪桶，鼻中闻到的尽是臭气和霉气。从西面墙上的小窗望
去，可以见到翰林府的一角。
LONG
	);

	set("exits", ([
		"east" : __DIR__"bingyin",
	]));
	set("objects", ([
                __DIR__"npc/dingdian" : 1,
        ]));

	create_door("east", "铁门", "west", DOOR_CLOSED);
	set("cost", 0);
	setup();
	replace_program(ROOM);
}

