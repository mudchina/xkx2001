//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov16.c

inherit ROOM;

void create()
{
	set("short", "沿池堤岸");
	set("long", @LONG
这里是滇池游客聚集之处，演鄯候高生世就时时承舟优胜于烟水缈蔼的滇池，
欣赏“梵刹于滇波向仰抑”的美景，并常停舟官渡，饮酒赋诗，被称之为“停舟
烟会”。这里的东浦彩虹、西山白雨、空中鹭鸶、晚霞潮红、归帆远影、无不给
人以美的享受。
LONG	);
	set("objects", ([
		__DIR__"npc/gongzi" : 1,
		__DIR__"npc/enu1" : 1,
		__DIR__"npc/enu2" :1,
		]));
	set("exits", ([
		"southeast" : __DIR__"minov17",
		"west" : __DIR__"minov14",
		]));
	set("area", "罗伽甸");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
