//Cracked by Roath
// Room: /d/dali/sangong.c

inherit ROOM;

void create()
{
	set("short", "府衙前厅");
	set("long", @LONG
这里是大理国机要府衙的前厅，乃大理官员商议国政军务之所，厅堂并不很
大，装饰朴素，厅门有御林军将士把手。除了东面出口，堂内另三面各有一门，
通往三公各自的司堂。
LONG);
	set("objects", ([
		__DIR__"npc/weishi5" : 2,
		__DIR__"npc/weishi2" : 2,
		]));
	set("exits", ([
		"northeast" : __DIR__"wangfu2",
		"north" : __DIR__"sangong2.c",
		"south" : __DIR__"sangong3.c",
		"west" : __DIR__"sangong1.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}
