//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov58.c

inherit ROOM;

void create()
{
	set("short", "葛鲁城");
	set("long", @LONG
此城是乌蛮族屈部的治府，屈部领葛鲁、昌州、德昌，面积颇大。附近多山
地丛林，居民多狩猎为生，河谷内低地也多草皮，适合放牧牛羊。此去北和西皆
入深山，东边平原上另有村镇。
LONG);
	set("objects", ([
		__DIR__"npc/wymuyren" : 1,
		__DIR__"npc/goat" : 2,
		]));
	set("exits", ([
		"northup" : __DIR__"minov59",
		"southeast" : __DIR__"minov57",
		"south" : __DIR__"minov54",
		]));
	set("area", "葛鲁城");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
