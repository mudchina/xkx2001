//Cracked by Roath
// Room: /d/beijing/kangqin/zhoulang7.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"houtang",
  "east" : __DIR__"moongate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
