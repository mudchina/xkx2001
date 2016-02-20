//Cracked by Roath
// Room: /city/milin.c

#include "ml.h"

inherit ROOM;

void create()
{
	set("short", "青竹林");
	set("long", @LONG
	这是一片茂密的青竹林，一走进来，你仿佛迷失了方向。
LONG
	);

	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"ml4",
		"south" : "/d/city/dongmen",
		"north" : __FILE__,
	]));

//	set("objects", ([
//		__DIR__"npc/zhangzi": 1,
//	]));

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}
