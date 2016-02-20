//Cracked by Roath
// Room: /city/quanzhou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "泉州港口");
	set("long", @LONG
quanzhou
需要更多的说明……
LONG
	);

	set("exits", ([
		"west" : __DIR__"road10",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

