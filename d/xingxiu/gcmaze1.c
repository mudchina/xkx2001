//Cracked by Roath
// Room: /d/xingxiu/gcmaze1.c
// Date: June 30, 96   Jay

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "高昌迷宫");
	set("long", @LONG
洞内甬道又黑又窄。走着走着突然开阔起来。只见里面是一间殿堂，
四壁供的都是泥塑木雕的佛像。偶然在壁上见到几个汉文，写的是「高
昌国国王」，「文泰」，「大唐贞观十三年」等等字样。墙上有一块匾
(bian)悬在一座老人的塑像上方。
LONG
	);

	set("item_desc", ([
		"bian" : "匾上写的是「大成至圣先师孔子位」。\n",
	]));

	set("exits", ([
		"out" : __DIR__"gcdoor",
                "enter" : __DIR__"gcmaze2",
	]));
	create_door("out","大铁门","enter",DOOR_CLOSED);

	set("cost", 6);
	setup();
}

