//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
一条向下曲折盘旋的通道。
LONG
        );

	set("exits", ([
		"westup" : __DIR__"jaderoad7",
		"westdown" : __DIR__"jaderoad9",
	]));

	set("cost", 1);
	setup();
}
