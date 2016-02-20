//Cracked by Roath
// Room: /d/dali/dlkd3.c

inherit ROOM;

void create()
{
	set("short", "睡房");
	set("long", @LONG
这是一间很大的客房，窗外是一片青竹林，靠窗子放了十几张竹床，不少客
人正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是空的，你蹑手蹑脚地走
了过去。
LONG);
	set("exits", ([
		"out" : __DIR__"dlkd2",
		]));
	set("cost", 2);
	set("hotel",1);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
