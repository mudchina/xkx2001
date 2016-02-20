//Cracked by Roath
// Room: /d/xiangyang/dongxin.c

inherit ROOM;

void create()
{
	set("short", "东新门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 7, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dongjie2",
]));

	setup();
	replace_program(ROOM);
}
