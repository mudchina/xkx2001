//Cracked by Roath
// Room: /d/xiangyang/wjiejing.c

inherit ROOM;

void create()
{
	set("short", "王桀井");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -15, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"qilidian",
]));

	setup();
	replace_program(ROOM);
}
