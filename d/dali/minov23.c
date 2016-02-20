//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov23.c

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
这里已经是平原的尽头，对面就是险峻的山岭了，一些的农田和罗伽部村民
的房屋零星地分布在山脚下，一些村民正在田里耕作。有条道路向东北的山上蜿
蜒而去。
LONG);
	set("objects", ([
		__DIR__"npc/bynong.c" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov24",
		"west" : __DIR__"minov20",
		]));
	set("area", "罗伽甸");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
