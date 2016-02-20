//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov20.c

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
这是一小块普通的水田地，南诏温暖潮湿，自古以来就以种植水稻为主。这
附近是大理地区少见的平原地形，主要以耕作为生的摆夷人开垦了一些的农田。
田地划分成小块，一些摆夷男子正在田里引着水牛耕作。有道路穿过农田向东而
去。
LONG);
	set("objects", ([
		__DIR__"npc/niu.c" : 1,
		__DIR__"npc/bynong.c" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"minov21",
		"west" : __DIR__"minov17",
		"east" : __DIR__"minov23",
		]));
	set("area", "罗伽甸");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
