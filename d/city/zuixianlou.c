//Cracked by Roath
// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "醉仙楼");
	set("long", @LONG
方圆数百里内提起醉仙楼可以说是无人不知，无人不晓。当年苏学士云游到
此，对醉仙楼的花雕酒赞不绝口，欣然为其题匾，流下一段传遍海内的佳话，从
此醉仙楼名声大震。楼下布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米
酒就赶路去了。楼上是雅座。
LONG
	);

	set("exits", ([
		"west" : __DIR__"beidajie2",
		"up" : __DIR__"zuixianlou2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if( present("xiao er", me) && dir="west" )
                return notify_fail("好端端地你想带店小二到那里去？！\n");

        return ::valid_leave(me, dir);
}


