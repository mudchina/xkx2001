//Cracked by Roath
// Room: /d/beijing/west/shibanlu2.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条青石板路，两边种了不少柏树，显得庄严肃穆。
往西走是西天门，北面是个花园，一阵阵浓郁的花香扑鼻而来。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"penshuichi",
  "west" : __DIR__"shibanlu1",
  "eastup" : __DIR__"danbiqiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
