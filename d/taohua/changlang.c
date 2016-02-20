//Cracked by Roath
//Kane

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是一道长长的由翠绿青竹搭成的走廊，周围种满翠竹，凤尾森森，龙吟细细，
令人精神为之一振。前面不知什麽地方飘来一股香气，你不由得有点饿了，左右两面
分别是桃花岛弟子的练功房，南面是水龙轩。
LONG
	);
	 set("exits", ([
		"south" : __DIR__"shuilong",
		"north" : __DIR__"chufang",
		"west" : __DIR__"liangong1",
		"east" : __DIR__"liangong2",
	]));
/*
	 set("objects", ([
		__DIR__"obj/tiexiao" : 1,
		__DIR__"obj/zhuxiao" : 2,
		__DIR__"obj/yijing3" : 1,
		__DIR__"obj/yijing4" : 1,
	]));

	set("no_fight", 1);
*/
	setup();
	replace_program(ROOM);
}
