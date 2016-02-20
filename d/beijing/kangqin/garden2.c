//Cracked by Roath
// Room: /d/beijing/kangqin/garden2.c

inherit ROOM;

void create()
{
	set("short", "小花园");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"woshi",
  "west" : __DIR__"moongate",
  "east" : __DIR__"fotang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
