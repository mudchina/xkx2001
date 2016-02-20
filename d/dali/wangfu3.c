//Cracked by Roath
// Room: /d/dali/wangfu3.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条青石板路，两边种了不少柏树，显得庄严肃穆。西面是个花园，一
阵阵浓郁的花香扑鼻而来。
LONG);
	set("exits", ([
		"north" : __DIR__"wangfu4.c",
		"south" : __DIR__"wangfu2.c",
		"west" : __DIR__"wangfu6.c",
		"east" : __DIR__"wangfu5.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
