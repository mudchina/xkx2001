//Cracked by Roath
// /d/wanshou/xunshouchang.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "驯兽场");
        set("long", @LONG
这就是万兽山庄的驯兽场，广场异常宽敞，场中数十头野兽嬉
戏奔跑着，带起漫天尘土，几个万兽山庄弟子穿着特制的牛皮衣帽
夹杂在野兽中间。驯兽场北边一条小径，通向山庄后面的树林，隐
隐的有虎啸声从那里传来。
LONG
        );
        set("exits", ([
		        "north" : __DIR__"shulin",
				"east" : __DIR__"zhenting",
        ]));

        set("outdoors", "wanshou-shanzhuang");

        set("objects", ([
                __DIR__"npc/bowei" : 1,
        ]));

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
