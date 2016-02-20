//Cracked by Roath
// Room: /d/dali/dinganfu2.c
#include "room.h"
inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这里是大理国低级官员的住所。大理段氏为中原武林世家，雇佣不少武林江
湖人士为臣，凡阶级在武将以下者都住在这里。东西方各有一些厢房，那是卧房。
南边是一间伙房，提供膳食。院角的一扇小门通往库房。
LONG);
	set("objects", ([
		__DIR__"npc/xiaosi" : 2,
		__DIR__"npc/weishi3" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"dinganfu",
		"south" : __DIR__"dinganfu5",
		"west"  : __DIR__"dinganfu3",
		"east"  : __DIR__"dinganfu4",
		"enter"	: __DIR__"dinganfu6",
		]));
	create_door("enter","木门","out", DOOR_CLOSED);
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir=="east" || dir=="west")
	{
		if (dir=="west" && me->query("gender")=="女性") return notify_fail("那是男子的厢房！\n");
		if (dir=="east" && me->query("gender")=="男性") return notify_fail("那是女子的厢房！\n");
	}
	return ::valid_leave(me, dir);
}
