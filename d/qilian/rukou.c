//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
你四周的光线顿时暗淡起来。面前是一个石壁，石壁上两柄火
把呼呼地燃烧着。
LONG
        );
        set("exits", ([
                "enter" : __DIR__"rukou1",
		"out" : __DIR__"qitian",
        ]));
//	set("objects", ([
 //               "/d/qilian/npc/tan-shi1" : 4,
//        ]));


	set("cost", 2);
        setup();
}
int valid_leave(object me, string dir)
{

        if (dir =="enter" && me->query("xjjt")<1 && me->query("xjjz")<1) { 
            if (present("wei shi", environment(me)))
                return notify_fail("玄劫卫士挡住你的去路：阁下非本教中人请回吧！\n");

        return 1;
}

        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}

