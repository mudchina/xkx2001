//Cracked by Roath
// Room: /d/beijing/east/shufang1.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guozihouyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
