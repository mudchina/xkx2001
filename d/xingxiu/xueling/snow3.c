//Cracked by Roath
// Ssy

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"雪岭"NOR);
        set("long", @LONG
这里风景颇好，山舞银蛇，原驰腊象。这种地方本不应有人的足  
迹，但东方却隐隐有一处山庄，不知是什么所在。
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"snow2",
                "east" : __DIR__"gate",
        ]));
        set("cost", 1);
        set("outdoors", "tianshan");
        setup();
}
