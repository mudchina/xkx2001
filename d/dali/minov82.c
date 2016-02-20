//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov82.c

inherit ROOM;

void create()
{
	set("short", "水田");
	set("long", @LONG
这是一片低洼平地的农田，除了田埂，全部都被水淹没着，一些普麽部的妇
女赤着脚在田里插秧。这个地区雨水充足，虽然没有江河流过，无需特别的灌溉，
每至春夏田里自然雨水溢满。
LONG);
	set("objects", ([
		__DIR__"npc/tynong" : 1,
		__DIR__"npc/niu" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov78",
		]));
	set("area", "鲁望镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
