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
		"east" : __DIR__"ml6",
		"west" : __FILE__,
		"south" : "/d/city/dongmen",
		"north" : __FILE__,
	]));
	set("cost", 3);
	setup();
//	replace_program(ROOM);
}
