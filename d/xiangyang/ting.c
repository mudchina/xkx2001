//Cracked by Roath
// Room: /d/xiangyang/ting.c

inherit ROOM;

void create()
{
	set("short", "芍药亭");
	set("long", @LONG
这是位在假山彼端的一座小亭子，亭上紫藤交错攀附，斜斜对著
古拙的山石，四周除了芍药之外，还遍植了桂花、玉兰、蜡梅等花木
，精恬静。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -8 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"xiaolu",
]));

	setup();
	replace_program(ROOM);
}
