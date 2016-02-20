//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov94.c

inherit ROOM;

void create()
{
	set("short", "村外草坡");
	set("long", @LONG
一大片山坡长满青草，正是放牧牛羊的好地方。这里地势甚高，天空呈深蓝
色，附近山岭树木已经甚少，基本上都是低矮灌木或草地。不少附近的村民在此
放牧。
LONG);
	set("objects", ([
		__DIR__"npc/wymuyang.c" : 1,
		__DIR__"npc/wymuyren.c" : 1,
		]));
	set("exits", ([
		"westdown" : __DIR__"minov91",
		]));
	set("area", "乌弄城");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
