//Cracked by Roath
// Room: /city/xinsu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "星宿");
	set("long", @LONG
xin su
需要更多的说明……
LONG
	);

	set("exits", ([
		"east" : __DIR__"road4",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

