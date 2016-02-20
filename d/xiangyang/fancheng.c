//Cracked by Roath
// Room: /d/xiangyang/fancheng.c

inherit ROOM;

void create()
{
	set("short", "樊城");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 2, "y" : 12 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"wangcg",
  "east" : __DIR__"zyfen",
]));

	setup();
	replace_program(ROOM);
}
