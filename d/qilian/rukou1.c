//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
两旁的火把呼呼地燃烧着。突然你眼前的石壁上出现“日月神
教”四个大字，洞外不时地传来阵阵的狼嚎。你脚下不小心碰到什
么东西，细看却是一个骷髅头。你顿时觉得毛骨悚然。
LONG
        );
        set("exits", ([
                "enter" : __DIR__"neiyuan",
                "out" : __DIR__"rukou",
        ]));

//	       set("objects", ([
 //               "/d/qilian/npc/tan-shi2" : 4,
 //       ]));


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

