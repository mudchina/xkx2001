//Cracked by Roath
// Room: /d/beijing/east/xiaojin1.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"jifangting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
