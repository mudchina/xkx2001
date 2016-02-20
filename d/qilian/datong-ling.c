//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大通岭");
        set("long", @LONG
这里就是大通岭，为贯连南祈连山脉的紧要之处。可见山羊，野兔奔行
其间，据闻此地盛产灵芝。再往上需得渐渐手脚并用。
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"bulang-po2",
                "westup" : __DIR__"niaoju",
		"northeast" : __DIR__"zhuti",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
