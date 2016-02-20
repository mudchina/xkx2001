//Cracked by Roath
// Room: /d/xiangyang/aozhangang.c

inherit ROOM;

void create()
{
	set("short", "鏖战岗");
	set("long", @LONG
这即是三国名将关羽水淹七军的古战场。这一带为古汉水河床淤积地层
，原处於汉水故道低洼地区。沧桑巨变，汉水改道，本已变成良田千顷。如今
被蒙古铁骑常日蹂躏後，见一片荒野。
LONG
	);
        set("coordinates", ([ "x" : -1, "y" : 12 ]) );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"dufugang",
  "westdown" : __DIR__"dengc",
]));

	setup();
	replace_program(ROOM);
}
