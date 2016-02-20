//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院，墙边上放着一个鸠摩智从少林寺偷来研习少林武功
用的木人。北面是活佛居住的昂欠楼，西边是天龙殿，南面是金刚院。
LONG
        );
        set("exits", ([
                "south" : __DIR__"jingang",
                "north" : __DIR__"angqian",
		"west" : __DIR__"tianlong",
		"east" :__DIR__"houyuan2",
        ]));

        set("objects", ([
		"/d/xueshan/npc/mu-ren" : 1
	]));
	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
