//Cracked by Roath
// Room: /d/beijing/east/guozidating.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guozihoutang",
  "south" : __DIR__"guoziqianyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
