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
		"west" : __FILE__,
		"south" : "/d/city/dongmen",
		"north" : __DIR__"ml3",
	]));
	set("cost", 3);
	setup();
//	replace_program(ROOM);
}
