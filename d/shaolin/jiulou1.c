//Cracked by Roath
// Room: /shaolin/jiulou1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "迎宾楼");
	set("long", @LONG
南阳城的迎宾楼是当地极有名的大酒楼。由于靠近汉江，故食客
们常有机会品尝远近闻名的汉江鲤鱼。迎宾楼的厨艺为南阳一绝，烧
出来的鲤鱼脂香肉嫩，稣红溜滑，常有客人远道而来，特为一饱口福。
LONG
	);

	set("exits", ([
		"east" : __DIR__"nanyang",
		"up" : __DIR__"jiulou2",
	]));

//	set("objects", ([
//		"/d/city/npc/xiaoer2" : 1,
//	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

