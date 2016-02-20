//Cracked by Roath
// Room: /d/dali/dalicheng16.c

inherit ROOM;

void create()
{
	set("short", "大和街");
	set("long", @LONG
大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一片太平热闹
景象。路口种了俩颗大菩提树，一踏入巷中，阵阵茶花香气扑鼻而来。
LONG);
	set("exits", ([
		"north" : __DIR__"dalicheng17",
		"south" : __DIR__"dalicheng18",
		"west" : __DIR__"dalicheng12",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}









