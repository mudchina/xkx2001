//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov69.c

inherit ROOM;

void create()
{
	set("short", "竹楼");
	set("long", @LONG
一间标准的台夷竹楼，四面墙壁皆是竹子，正中砌了一座正方形的灶台，其
内架置着铁炉。夷族传统席地而睡，是以屋内无床，延墙摆有垫褥，屋舍内除了
石堆祭台外别无家具。
LONG);
	set("objects", ([
		__DIR__"npc/tykid" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov68",
		]));
	set("area", "武定镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
