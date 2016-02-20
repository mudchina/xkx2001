//Cracked by Roath
// Room: /d/beijing/west/beihaibeian2.c

inherit ROOM;

void create()
{
	set("short", "北海北岸");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"beihaidongan",
  "west" : __DIR__"beihaibeian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
