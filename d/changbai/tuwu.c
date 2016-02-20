//Cracked by Roath
// Room: tuwu.c

inherit ROOM;

void create()
{
	set("short", "小土屋");
	set("long", @LONG
这是一座用黄土垒成的小屋，屋内打扫的很干净。四周的墙壁上挂满了
各种棍子，钎子，开山斧，小锯子等工具，看来似乎是采参所用的工具。屋
内西面的火炕上坐着一位上了年纪的老人，正在吸着旱烟袋。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"xiaoxiang",
	]));
        set("objects",([
		__DIR__"npc/batou" : 1,
	]));
        

	setup();
	replace_program(ROOM);
}

