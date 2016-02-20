//Cracked by Roath
// Room: /d/heimuya/clifftop.c
// Date: fear 1999/12/18
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "崖顶");
        set("long", @LONG
这里便是黑木崖顶了，悬崖下的万仞深谷被云烟缭
绕，看不清尽头。崖顶地上放着一只大竹篓，悬崖下端
有绞索绞盘，可以将竹篓绞下去。
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"pailou",
                "enter" : __DIR__"basket",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

