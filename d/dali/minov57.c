//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov57.c

inherit ROOM;

void create()
{
	set("short", "蜜纳甸");
	set("long", @LONG
这里是乌夷分支乌蒙族阔部聚居的镇子，阔部领蜜纳甸和阔州。附近有溪流
汇入泸水，灌溉颇便利，因而农业相对谷中其他地区较发达。镇中尽是些简陋的
民居，也无甚客商过往。
LONG);
	set("objects", ([
		__DIR__"npc/wygirl" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov58",
		"southup" : __DIR__"minov44",
		"west" : __DIR__"minov54",
		]));
	set("area", "葛鲁城");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
