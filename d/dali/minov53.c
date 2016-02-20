//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov53.c

inherit ROOM;

void create()
{
	set("short", "巴的甸");
	set("long", @LONG
这里就是大理西部要镇巴的甸，是乌夷的重要治府，多个乌夷部落分布在附
近。坐于东泸水谷地正中，巴的甸四周多农田，以此为中心，道路四通八达连接
各方的部落。
LONG);
	set("exits", ([
		"eastup" : __DIR__"minov44",
		"north" : __DIR__"minov54",
		"south" : __DIR__"minov52",
		]));
	set("area", "泸水沿岸");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
