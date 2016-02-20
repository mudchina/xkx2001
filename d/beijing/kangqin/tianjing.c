//Cracked by Roath
// Room: /d/beijing/kangqin/tianjing.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"houtang",
  "west" : __DIR__"zhoulang4",
  "north" : __DIR__"dating",
  "east" : __DIR__"zhoulang3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
