//Cracked by Roath
// Room: /city/beidajie1.c
// YZC 1995/12/04
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "北集市");
	set("long", @LONG
这里是集市上买鲜肉的地方。肉摊上有各种各样的肉类应有尽有。向南可通
向扬州城的中心大街。东面的楼上写着“天宝阁”，那里是人们读书消遣的好去
处。西边是一家生意兴隆的客栈，来自各地的人们进进出出，据说也是情人们的
幽会地点。
LONG
	);
	set("outdoors", "city");

	set("exits", ([
		"west" : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"northwest" : __DIR__"majiu",
		"east" : __DIR__"tianbaoge",
		"north" : __DIR__"beidajie2",
	]));
	set("objects", ([
		__DIR__"npc/xunbu" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

