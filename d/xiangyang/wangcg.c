//Cracked by Roath
// Room: /d/xiangyang/wangcg.c

inherit ROOM;

void create()
{
	set("short", "望城岗");
	set("long", @LONG
你来到一处高岗之上，从此可望汉水南边的襄阳城。这地势较高，又
可一望数。故而蒙古大军先锋到时经常驻扎在此。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 2, "y" : 11 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"fancheng",
  "southwest" : __DIR__"shanlu2",
]));

	setup();
	replace_program(ROOM);
}
