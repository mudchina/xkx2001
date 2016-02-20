//Cracked by Roath
// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
繁华的南大街上向南北两头延伸。南边是南城门，北边通往市中心。西边是
一家顾客众多的酒馆，三教九流人士都在那里谈天说地。东边一座两层的楼房传
来阵阵浪笑，那就是天下闻名的丽春院。这个集市是南北集市中较热闹的一个，
可能是由于酒馆和丽春院在这的缘故吧。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"lichunyuan",
		"south" : __DIR__"nanmen",
		"west" : __DIR__"jiuguan",
		"north" : __DIR__"nandajie2",
	]));

        set("objects", ([
                CLASS_D("shaolin") + "/tuoboseng" : 1,
        ]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && (int)me->query("age") < 18 && !wizardp(me))
		return notify_fail("小朋友不要到那种地方去！！\n");
	return 1;
}
