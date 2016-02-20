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
		"eastup" : __DIR__"jaderoad8",
		"eastdown" : __DIR__"jaderoad10",
	]));

	set("cost", 1);
	setup();
}
