//Cracked by Roath
// Room: /d/xiangyang/zyfen.c

inherit ROOM;

void create()
{
	set("short", "状元坟");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : 12 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fancheng",
]));

	setup();
	replace_program(ROOM);
}
