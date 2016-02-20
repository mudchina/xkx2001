//Cracked by Roath
// Room: /city/bingqiku.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵器库");
	set("long", @LONG
这里是兵器库，到处银光闪闪，让人眼花缭乱。宝刀、宝剑、金箍棒，大刀、
长剑、哨棒，短刀、短剑、短棍，各色各样的兵器应有尽有，你一时不知道挑什
么好。
LONG
	);

	set("exits", ([
		"north" : __DIR__"bingyin",
	]));

	create_door("north", "铁门", "south", DOOR_CLOSED);
	set("cost", 0);
	setup();
	replace_program(ROOM);
}

