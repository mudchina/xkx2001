//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "兰州南门");
        set("long", @LONG
这是兰州南城门，一望无际的大草原从这里开始。
LONG
        );
        set("exits", ([
                "south" : __DIR__"prairie",
                "north" : __DIR__"lanzhou",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
