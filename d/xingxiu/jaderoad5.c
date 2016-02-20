//Cracked by Roath
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "大殿门口");
	set("long", @LONG
这是白玉峰大殿的门口，只见大殿中到处都是骸骨，刀剑散
满了一地，想来当日必曾有过一场激战。
LONG
        );

	set("exits", ([
		"north" : __DIR__"jadehall",
		"south" : __DIR__"jaderoad4",
	]));

	set("cost", 1);
	setup();
}
