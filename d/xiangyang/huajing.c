//Cracked by Roath
// Room: /d/xiangyang/huajing.c

inherit ROOM;

void create()
{
	set("short", "花径");
	set("long", @LONG
你走在一条铺设著鹅卵石的小径上，两旁花树繁盛，似闻花香
流动，叠荫重重，一片静谧，南边就是後花园。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -5 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"neitang",
  "south" : __DIR__"huayuan",
]));

	setup();
	replace_program(ROOM);
}
