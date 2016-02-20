//Cracked by Roath
// /d/zhongnan/liangong1.c 练功房
// by sdong

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
练功房是供弟子修练内功，或研读武学书籍之处。房内并无特别
摆设，以免弟子行功时分心，耽误了进度。东边是男厢房。西边是演
武厅。
LONG
        );

        set("exits", ([
                "west" : __DIR__"yinwutin",
                "east" : __DIR__"nanqinshi",
        ]));

        set("cost", 0);
        setup();

}

int valid_leave(object me, string dir)
{
        if ( me->query("gender") == "女性" && dir == "east" && !wizardp(me) )
                return notify_fail("看清楚点，那是男厢房！\n");

        return ::valid_leave(me, dir);
}
