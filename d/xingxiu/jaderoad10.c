//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
密道至此已是尽头，前方似乎有一线光亮。
LONG
        );

	set("exits", ([
		"westup" : __DIR__"jaderoad9",
		"out" : __DIR__"feicui",
	]));

	set("cost", 1);
	setup();
}
