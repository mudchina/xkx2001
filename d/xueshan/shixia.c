//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "石峡谷");
        set("long", @LONG
这是一处荒凉的峡谷，杳无人迹。出了峡谷往东是一片大草原，
往西则进山了。
LONG
        );
        set("exits", ([
                "west" : __DIR__"shanlu1",
                "east" :"/d/qilian/prairie2",
        ]));
	set("objects", ([
                "/kungfu/class/xuedao/shanyong": 1,
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
