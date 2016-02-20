//Cracked by Roath
// Room: /d/beijing/kangqin/zhongmen.c

inherit ROOM;

void create()
{
	set("short", "中门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dating",
  "north" : __DIR__"tingyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
