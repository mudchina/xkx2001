//Cracked by Roath
// Room: /d/dali/xiaguan.c

inherit ROOM;

void create()
{
	set("short", "下关城");
	set("long", @LONG
下关城，又名龙尾城，为阁罗凤所筑，唐代已极繁荣。城区萦抱苍山南麓数
里，洱水绕城南而过，端的风景如画。此去南边不远即是大理城，东面有太和城，
另有道路通向西北。此附近居民以乌夷、台夷为主，也有少量摆夷。
LONG);
	set("objects", ([
		__DIR__"npc/wyshang.c" : 1,
		__DIR__"npc/tyshang.c" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov84",
		"northeast" : __DIR__"cangshan.c",
		"south" : __DIR__"esqiao",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
