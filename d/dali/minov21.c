//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov21.c

inherit ROOM;

void create()
{
	set("short", "杆栏");
	set("long", @LONG
摆夷族大多依树积木以居其上，就是杆栏，在夷语里叫做榔盘。其构造大致
略似楼，侧面开门，有梯可上下，上阁如车盖状，中层住人，这里是下层，一般
为牛羊圈。
LONG);
	set("objects", ([
		__DIR__"npc/goat.c" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"minov20",
		"up" : __DIR__"minov22",
		]));
	set("area", "罗伽甸");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
