//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "爱力生");
        set("long", @LONG
这里是一遍流沙。抬眼望去，黄茫茫一片沙漠，似无尽头，直连天边，
一不留神踏入，就石牛入海，消失得无影无踪了，蒙古语称为爱力生。
LONG
        );
        set("exits", ([
                "north" : __DIR__"aili2",
                "west" : __DIR__"aili2",
        ]));


	set("cost", 5);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
