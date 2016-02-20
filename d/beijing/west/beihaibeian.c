//Cracked by Roath
// Room: /d/beijing/west/beihaibeian.c

inherit ROOM;

void create()
{
	set("short", "北海北岸");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beihaibeian2",
  "southwest" : __DIR__"beihaixian2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
