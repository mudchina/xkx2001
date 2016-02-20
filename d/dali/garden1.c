//Cracked by Roath
// Room: /d/dali/garden1.c

inherit ROOM;

void create()
{
	set("short", "茶花园入口");
	set("long", @LONG
在一堵青色的石墙后面，隐隐可以看到一排排的垂柳，鼻中闻到随风漂来的
淡淡茶花香味，心中不禁一阵清明。
LONG);
	set("exits", ([
		"west" : __DIR__"wangfu5.c",
		"enter" : __DIR__"garden2.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
