//Cracked by Roath
// wdroad4.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，四周静悄悄的。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"wdroad5",
		"east" : __DIR__"wdroad3",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

