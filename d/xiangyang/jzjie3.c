//Cracked by Roath
// Room: /d/xiangyang/jzjie3.c

inherit ROOM;

void create()
{
	set("short", "荆州街");
	set("long", @LONG
这已是荆州街的末段，集市至此已将尽。路旁虽仍有不少人群，但已不似
南面那样拥挤繁华。向北再去便可到襄阳城的小北门。东面似乎有一间售卖兵器
的小店。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
        set("coordinates", ([ "x" : 3, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"bingqid",
  "north" : __DIR__"beimen",
  "south" : __DIR__"jzjie2",
]));

	setup();
	replace_program(ROOM);
}
