//Cracked by Roath
// /d/zhongnan/liangong2.c 练功房
// by sdong

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
练功房是供弟子修练内功，或研读武学书籍之处。房内并无特别
摆设，以免弟子行功时分心，耽误了进度。北边是女厢房。南边是静
室。
LONG
        );

        set("exits", ([
                "north" : __DIR__"nyuqinshi",
                "south" : __DIR__"jinshi",
        ]));

        set("cost", 0);
        setup();

}

int valid_leave(object me, string dir)
{
        if ( me->query("gender") == "男性" && dir == "north" && !wizardp(me) )
                return notify_fail("看清楚点，那是女厢房！\n");

        return ::valid_leave(me, dir);
}
