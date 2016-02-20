//Cracked by Roath
// /d/city/wdroad1.c
// by xiang
// modified by aln  2 / 98

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。南边就是江南一带有名的太湖，西面
是崇山峻岭，北边通向扬州城。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
                "south" : "/d/taihu/yixing",
		"north" : __DIR__"nanmen",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

