//Cracked by Roath
// Room: /d/dali/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路两旁间或可见
一些夷族的村镇。山路向南蜿蜒着。
LONG);
	set("objects", ([
		__DIR__"npc/wujian": 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov46",
		"northeast" : __DIR__"minov43",
		"southeast" : __DIR__"shanlu2",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
