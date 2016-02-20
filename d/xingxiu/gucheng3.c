//Cracked by Roath
// 古城
// maco

inherit ROOM;

void create()
{
	set("short", "古城");
	set("long", @LONG
城中道路曲折如迷宫，令人眼花缭乱。路上屋子多已朽坏，
景象奇特可怖，透着一股寂静的气氛。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gucheng2",
		"west" : __DIR__"gucheng5",
		"north" : __DIR__"gucheng4",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

