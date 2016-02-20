//Cracked by Roath
// 古城
// maco

inherit ROOM;

void create()
{
	set("short", "古城破屋");
	set("long", @LONG
这是古城中心就近的一间屋子。地下凸起一物，形状有异，
盘根错节，却是个极大的树根。
LONG
	);

	set("exits", ([
		"south" : __DIR__"gucheng3",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}
