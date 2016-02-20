//Cracked by Roath
// Room: /d/beijing/east/guozihoutang.c

inherit ROOM;

void create()
{
	set("short", "后堂");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guozihouyuan",
  "south" : __DIR__"guozidating",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
