//Cracked by Roath
// Room: /d/beijing/east/qianyuan.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yumadamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
