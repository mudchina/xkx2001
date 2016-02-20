//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov47.c

inherit ROOM;

void create()
{
	set("short", "易溪部");
	set("long", @LONG
易溪部也是乌夷族乌杂蛮的部落。这里处半坡地，附近有不少农田，但农业
落后，需要换季轮耕，因而村民经常迁徙，镇子里除了祭祀大屋外，其它房屋都
很简陋。
LONG);
	set("objects", ([
		__DIR__"npc/wygirl" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov49",
		"northeast" : __DIR__"minov46",
		"south" : __DIR__"minov48",
		]));
	set("area", "泸水沿岸");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
