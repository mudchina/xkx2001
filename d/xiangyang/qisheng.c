//Cracked by Roath
// Room: /d/xiangyang/qishengmen.c

inherit ROOM;

void create()
{
	set("short", "奇胜门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : 6 ]) );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"beijie3",
  "north" : __DIR__"tulu4",
]));

	setup();
	replace_program(ROOM);
}
