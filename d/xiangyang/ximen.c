//Cracked by Roath
// Room: /d/xiangyang/ximen.c

inherit ROOM;

void create()
{
	set("short", "西门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
        set("coordinates", ([ "x" : -6, "y" : -7 ]) );
	set("no_clean_up", 0);
	set("srhot", "西门");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"djtai",
  "west" : __DIR__"tulu2",
]));
	set("shoot", "西门");

	setup();
	replace_program(ROOM);
}
