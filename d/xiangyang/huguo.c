//Cracked by Roath
// Room: /d/xiangyang/huguo.c

inherit ROOM;

void create()
{
	set("short", "护国门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : -9 ]) );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"nanjie2",
]));

	setup();
	replace_program(ROOM);
}
