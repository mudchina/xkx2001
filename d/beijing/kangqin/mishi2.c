//Cracked by Roath
// Room: /d/beijing/kangqin/mishi2.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"mishi",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
