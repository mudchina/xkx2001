//Cracked by Roath
// Room: /d/dali/sangong1.c

inherit ROOM;

void create()
{
	set("short", "司空堂");
	set("long", @LONG
这是一间端正堂皇的公堂，是大理国司空巴天石平常办理公务的司所。司空
管辖内政事务，如税务、道路桥梁修建等。所司紧要，政务繁忙，文案上高高堆
起一叠公文。
LONG);
	set("objects", ([
		__DIR__"npc/ba-tianshi" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"sangong",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}
