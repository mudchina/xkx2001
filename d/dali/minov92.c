//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov92.c

inherit ROOM;

void create()
{
	set("short", "乌夷民居");
	set("long", @LONG
这是一所乌夷族的房屋。乌夷民居的建地和走向讲究依傍四面山势，一般以
石为墙和基，以木为梁，结构大致和汉人房屋相仿，皆是平房，石砌围墙。这家
院内有一圈牲畜，猪牛羊皆有。
LONG);
	set("objects", ([
		__DIR__"npc/wymuyang.c" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"minov91",
		]));
	set("area", "乌弄城");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
