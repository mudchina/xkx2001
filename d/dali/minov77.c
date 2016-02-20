//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov77.c

inherit ROOM;

void create()
{
	set("short", "龙口城");
	set("long", @LONG
这里已到大理南疆了，龙口城南临元江，属临江路。大理国南部虽广有千多
里，但大城镇较稀少，此地虽离大理中心不远，却也算南部的重要关口之一了，
是和南方临国通商的口岸。由此北去二十五里即是喜州城，南边沿元江有不少台
夷村庄。大理官府在此有些驻军。
LONG);
	set("objects", ([
		__DIR__"npc/dalishibing" : 2,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov72",
		]));
	set("area", "龙口城");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
