//Cracked by Roath
// Room: /d/heimuya/cliff.c
// Date: fear 1999/12/18
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "断崖");
        set("long", @LONG
前面是一座陡峭的悬崖，峭壁下面是万丈深谷，悬
崖对面是座高山。地上放着一只大竹篓，悬崖顶端有绞
索绞盘，可以将竹篓绞上去。
LONG
        );

        set("exits", ([
                "south" : __DIR__"shimen",
                "enter" : __DIR__"basket",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

