//Cracked by Roath
// Room: /d/xiangyang/huajing2.c

inherit ROOM;

void create()
{
	set("short", "花径");
	set("long", @LONG
你走在一条铺设著鹅卵石的小径上，两旁花树繁盛，可闻花香
流动，叠荫重重，四下一片静谧，东边是一列青瓦厢房，南面有间
小斋。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 4, "y" : -6 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"huilang1",
  "south" : __DIR__"shuzhai",
  "west" : __DIR__"huayuan",
]));

	setup();
	replace_program(ROOM);
}
