//Cracked by Roath
// Room: /d/xiangyang/shuzhai.c

inherit ROOM;

void create()
{
	set("short", "书斋");
	set("long", @LONG
一间清静的书斋，木案上陈列著文房四宝，後头书架上满是古
书经典，整齐有序。照壁上悬著一幅泼墨山水，古意盎然。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 4, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huajing2",
]));

	setup();
	replace_program(ROOM);
}
