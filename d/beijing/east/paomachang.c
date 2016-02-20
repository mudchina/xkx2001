//Cracked by Roath
// Room: /d/beijing/east/paomachang.c

inherit ROOM;

void create()
{
	set("short", "跑马场");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"majiu3",
  "west" : __DIR__"majiu5",
  "south" : __DIR__"zhongmen",
  "east" : __DIR__"majiu1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
