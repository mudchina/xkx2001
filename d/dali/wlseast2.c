//Cracked by Kafei
// Room: /d/dali/wlseast2.c
// AceP

inherit ROOM;

int do_drop(object);

void create()
{
	set("short", "乱石堆");
	set("long", @LONG
山坳的一处乱石堆，周围团团坐着二十几人，当中一块高岩之上
坐了个瘦小的老者，高处旁人，料来便是神农帮帮主司空玄了。
LONG );

	set("exits", ([
		"down" : __DIR__"wlseast1",
	]));

	set("objects", ([
		__DIR__"npc/snbz": 5,
		__DIR__"npc/sikong": 1,
		]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
