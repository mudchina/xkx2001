//Cracked by Roath
// Room: /city/shenlong.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "神龙教");
	set("long", @LONG
shen long
需要更多的说明……
LONG
	);

	set("exits", ([
		"west" : __DIR__"road7",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

