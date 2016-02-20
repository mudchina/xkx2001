//Cracked by Roath
// taiziyan.c  太子岩
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "太子岩");
	set("long", @LONG
	这里是群山环抱中的太子岩，岩上有一块三清石和一座太子亭。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"shanlu3",
		"southdown" : __DIR__"langmei",
	]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

