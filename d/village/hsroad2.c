//Cracked by Roath
// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，南边隐约可见到扬州城的城墙。
西北面一条驿道通向汉江边。
LONG
	);
        set("outdoors", "huashan");

	set("exits", ([
		"south" : __DIR__"hsroad1",
		"northwest" : "/d/shaolin/yidao",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

