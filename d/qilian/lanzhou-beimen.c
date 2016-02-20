//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "兰州北门");
        set("long", @LONG
这里是西北第一大城兰州的北门。出此门向东北跨过萧家桥可抵
中原。
LONG
        );
        set("exits", ([
                "south" : __DIR__"lanzhou",
                "northeast" : __DIR__"xiaojiaqiao",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
