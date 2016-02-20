//Cracked by Roath
// Room: /d/beijing/kangqin/garden.c

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shiwu",
  "west" : __DIR__"chufang",
  "north" : __DIR__"houtang",
  "east" : __DIR__"wuqiku",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
