//Cracked by Roath
// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
	你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。南边通向扬州城。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"hsroad2",
		"south" : "/d/city/beimen",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

