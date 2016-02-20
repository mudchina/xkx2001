//Cracked by Roath
// Room: /d/dali/dalicheng10.c

inherit ROOM;

void create()
{
	set("short", "太和居");
	set("long", @LONG
这是大理城内最大的酒楼，楼下卖些大理的小吃，过往行人常常买来作路菜。
楼上是雅座。
LONG);
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"dalicheng9",
		"up" : __DIR__"dalicheng11",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}

