//Cracked by Roath
// Room: /d/dali/sangong3.c

inherit ROOM;

void create()
{
	set("short", "司徒堂");
	set("long", @LONG
一所清静的书堂，打扫得干干净净。司徒一般负责官吏选拔等文书工作，是
以堂内文卷堆积。时有官员来此拜领印玺公文等物，前往所排遣的任地公干。
LONG);
	set("objects", ([
		__DIR__"npc/hua-hegen" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"sangong",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}
