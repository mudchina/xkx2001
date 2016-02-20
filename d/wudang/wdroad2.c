//Cracked by Roath
// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，东南边隐约可见到扬州城的城墙。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"wdroad3",
		"southeast" : "/d/xingxiu/xxroad2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

