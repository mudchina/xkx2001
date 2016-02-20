//Cracked by Roath
// Room: /d/beijing/west/nanhainanan.c

inherit ROOM;

void create()
{
	set("short", "南海南岸");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hubianxiaodao5",
  "east" : __DIR__"hubianxiaodao6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
