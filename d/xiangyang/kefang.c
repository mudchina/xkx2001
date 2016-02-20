//Cracked by Roath
// Room: /d/xiangyang/kefang.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
郭府时常有宾客来访，是以访客的卧房也洒扫得甚是整洁，床
铺铺盖均是一尘不染，窗外可以见到花园中花影摇曳。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 6, "y" : -8 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huilang2",
]));
	set("sleep_room", "1");

	setup();
	replace_program(ROOM);
}
