//Cracked by Roath
// Room: /d/quanzhou/qzroad5.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "武夷山路");
	set("long", @LONG
你走在东南第一山脉武夷山上。海风从东面吹来，带着几分寒意。
南边就是著名的海港泉州了。
LONG
	);

	set("exits", ([
                "south" : __DIR__"shanlu1",
                "north" : "/d/hangzhou/road62",
	]));

        set("objects", ([
		"/d/wudang/npc/yetu" : 2 ]));

	set("outdoors", "quanzhou");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

