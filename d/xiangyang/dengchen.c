//Cracked by Roath
// Room: /d/xiangyang/dengcheng.c

inherit ROOM;

void create()
{
	set("short", "邓城");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : 12 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"aozhangang",
]));

	setup();
	replace_program(ROOM);
}
