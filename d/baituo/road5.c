//Cracked by Roath
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这是条偏僻的小径，蜿蜒地绕入白驼山，四周悄然无声。遥望北
方，是一座深邃的山谷，气氛阴森，那就是白驼山的蛇谷。东边的岔
路通往白驼山庄的蛇场。
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"shechang",
	    "north" : __DIR__"shegu1",
	    "southeast" : __DIR__"road4",
	]));
	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
