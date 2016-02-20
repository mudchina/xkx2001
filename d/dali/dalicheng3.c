//Cracked by Roath
// Room: /d/dali/dalicheng3.c

inherit ROOM;

void create()
{
	set("short", "蛇骨塔");
	set("long", @LONG
蛇骨塔位于大理城内，建在点苍山斜阳峰东坡。相传洱海有妖蛇名“薄劫”，
其尾塞海口，洪水泛滥，有勇士段赤城只身入洱海与妖蛇同归于尽。后人建塔以
震水势，用蛇骨灰塔，水势自息。这是一座密椽式方形砖塔。
LONG);
	set("objects", ([
		"/d/village/npc/kid" : 2,
		]));
	set("exits", ([
		"east" : __DIR__"dalicheng2",
		"west" : __DIR__"dalicheng4",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
