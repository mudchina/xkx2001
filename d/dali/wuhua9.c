//Cracked by Roath
// Room: /d/dali/wuhua9.c

inherit ROOM;

void create()
{
	set("short", "贵宾房");
	set("long", @LONG
这里通常是南方部族首领进都时的住所。这里的摆设多与其洞中相仿，地上
垫了几张虎皮，豹皮。墙边则是一张乌檀木的大床，东壁上挂了几把弯刀，枪，
铲之物。
LONG);
	set("objects", ([
		__DIR__"npc/leader1" : 1,
		]));
	set("exits", ([
		"out" : __DIR__"wuhua7.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
