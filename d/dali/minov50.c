//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov50.c

inherit ROOM;

void create()
{
	set("short", "高黎山东坡");
	set("long", @LONG
这里是高黎山的东坡，向东俯视奔淌而过的东泸水，远远眺望跨谷相对的碧
罗雪山。此去再向西全是崇山峻岭，人烟稀少。山间林深兽多，乌夷族的猎人经
常进山打猎。
LONG);
	set("objects", ([
		__DIR__"npc/goat" : 1
		]));
	set("exits", ([
		"eastdown" : __DIR__"minov49",
		"west" : __DIR__"minov51",
		]));
	set("area", "泸水沿岸");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
