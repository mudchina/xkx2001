//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov43.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路两旁间或可见
一些夷族的村镇。山路向南蜿蜒着。
LONG);
	set("exits", ([
		"northup" : __DIR__"minov42",
		"southwest" : __DIR__"shanlu1",
		]));
	set("area", "碧罗雪山");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
