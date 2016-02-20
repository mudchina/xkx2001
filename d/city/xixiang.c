//Cracked by Roath
// Room: /city/xixiang.c
// YZC 1995/12/04 
// Jay 2/3/97

inherit ROOM;

void create()
{
	set("short", "丫鬟卧房");
	set("long", @LONG
这是丫鬟的房间。房中陈设简单，没什么东西。
LONG
	);

	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/juyou" : 1,
	]));
	set("cost", 0);
	setup();
	replace_program(ROOM);
}

