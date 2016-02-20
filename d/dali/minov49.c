//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov49.c

inherit ROOM;

void create()
{
	set("short", "阿头部");
	set("long", @LONG
阿头部是乌杂蛮的部落，和附近的乌蛮一样，也属于乌夷。这里山高林密，
不熟的人轻率进山，很容易迷路丧命。深山对乌夷猎人来说却是聚宝盆，山中
野物皆是美味。
LONG);
	set("objects", ([
		__DIR__"npc/wylieren" : 1,
		]));
	set("exits", ([
		"southeast" : __DIR__"minov47",
		"westup" : __DIR__"minov50",
		"north" : __DIR__"minov52",
		]));
	set("area", "泸水沿岸");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
