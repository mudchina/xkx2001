//Cracked by Roath
// Room: /d/xingxiu/gcmaze3.c
// Date: June 30, 96   Jay

inherit ROOM;

void create()
{
	set("short", "高昌迷宫");
	set("long", @LONG
这里到处放满了汉人的武器、用具。潮湿的空气使大部
分物品都已发霉。
LONG
	);

	set("objects", ([
		__DIR__"npc/huahui" : 1,
		"/d/village/obj/zhujian" : 1,
		"/d/shaolin/obj/mudao" : 1,
	]));

	set("exits", ([
                "out" : __DIR__"gcmaze2",
	]));

	set("cost", 7);
	setup();
	replace_program(ROOM);
}

