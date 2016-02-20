//Cracked by Roath
// Room: /d/dali/tusi3.c

inherit ROOM;

void create()
{
	set("short", "议事厅");
	set("long", @LONG
议事厅中央有神龛，龛下陈列着刀、叉、矛、戟等兵器。宽阔的大楼上下，
柱梁粗实。厅堂宽敞，前后各有一长排坐栏，供人纳凉憩息。
LONG);
	set("objects", ([
		__DIR__"npc/datusi" : 1,
		__DIR__"npc/touren" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"tusi4",
		"east" : __DIR__"tusi2",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
