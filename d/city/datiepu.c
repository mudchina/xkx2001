//Cracked by Roath
// Room: /city/datiepu.c
// YZC 1995/12/04 
// RYU 1997/3/18

inherit ROOM;

void create()
{
	set("short", "打铁铺");
	set("long", @LONG
这是一家简陋的打铁铺，中心摆着一个火炉，炉火把四周照得一片通红，你
一走进去就感到浑身火热。墙角堆满了已完工和未完工的菜刀、铁锤、铁棍、匕
首、盔甲等物。一位铁匠满头大汗挥舞着铁锤，专心致志地在打铁。
LONG
	);

	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
	set("objects", ([
		__DIR__"npc/tiejiang" : 1,
                __DIR__"npc/gongjiang" : 1,
	]));

	set("day_shop", 1);
	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if( present("wang tiejiang", me) )
		return notify_fail("你想拐带铁匠做什么？欺负老实人啊！\n");

	return ::valid_leave(me, dir);
}

