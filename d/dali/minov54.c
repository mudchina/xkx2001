//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov54.c

inherit ROOM;

void create()
{
	set("short", "镇雄");
	set("long", @LONG
这里是乌撒部的聚居中心，乌撒是乌蛮族的大部，属乌夷，领有巴的甸、镇
雄、和附近的威宁。这是一座石砌小城，人口不多，居民散居在镇子附近，镇子
上主要是一些商铺和祭祀所。
LONG);
	set("objects", ([
		__DIR__"npc/wymuyang" : 1,
		__DIR__"npc/wyshang" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov58",
		"south" : __DIR__"minov53",
		"west" : __DIR__"minov55",
		"east" : __DIR__"minov57",
		]));
	set("area", "葛鲁城");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
