//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "通道");
	set("long", @LONG
一处狭小的通道，转弯处有一扇小门。
LONG
	);

	set("exits", ([
		"south" : __DIR__"jadehall2",
		"west" : __DIR__"jaderoom2",

	]));

	set("cost", 1);
	setup();
}
