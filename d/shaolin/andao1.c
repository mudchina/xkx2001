//Cracked by Roath
// Room: /d/shaolin/andao1.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "暗道");
	set("long", @LONG
这是一个阴暗潮湿的地道，四壁用粗糙的片岩垒垛而成，一
颗颗水珠沿着墙壁滚下来，溅在地上。也许是因为长时间无人通
行的缘故，整个地道弥漫着一股腐尸般的恶臭。
LONG
	);

	set("exits", ([
		"south" : __DIR__"rukou",
		"north" : __DIR__"jianyu1",
	]));

	create_door("north","木门","south",DOOR_CLOSED);
	set("objects",([
		__DIR__"npc/ad-laoshu" : 1,
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}



