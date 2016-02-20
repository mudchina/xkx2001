//Cracked by Roath
// Room: /city/tianshan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "天山");
	set("long", @LONG
tian shan
需要更多的说明……
LONG
	);

	set("exits", ([
		"east" : __DIR__"road2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

