//Cracked by Roath
// Room: /d/beijing/taihe/tiananmenlou.c

inherit ROOM;

void create()
{
	set("short", "空房间");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tiananmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
