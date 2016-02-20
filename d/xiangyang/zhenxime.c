//Cracked by Roath
// Room: /d/xiangyang/zhenximen.c

inherit ROOM;

void create()
{
	set("short", "镇西门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xijie2",
  "west" : __DIR__"tulu1",
]));

	setup();
	replace_program(ROOM);
}
