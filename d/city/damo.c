//Cracked by Roath
// Room: /city/damo.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "大漠");
	set("long", @LONG
da mo 
需要更多的说明……
LONG
	);

	set("exits", ([
		"east" : __DIR__"road1",
	]));

	set("cost", 5);
	setup();
	replace_program(ROOM);
}

