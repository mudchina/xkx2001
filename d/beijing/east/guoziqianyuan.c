//Cracked by Roath
// Room: /d/beijing/east/guoziqianyuan.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guozidating",
  "west" : __DIR__"guoxixiang",
  "south" : __DIR__"guozidamen",
  "east" : __DIR__"guodongxiang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
