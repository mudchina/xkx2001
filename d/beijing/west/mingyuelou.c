//Cracked by Roath
// Room: /d/beijing/west/mingyuelou.c

inherit ROOM;

void create()
{
	set("short", "明月楼");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tianqiao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
