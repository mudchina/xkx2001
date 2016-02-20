//Cracked by Roath
// Room: /d/beijing/west/nanhaidongan.c

inherit ROOM;

void create()
{
	set("short", "南海东岸");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hubianxiaodao6",
  "north" : __DIR__"hubianxiaodao4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
