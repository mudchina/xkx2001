//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大雪山");
        set("long", @LONG
冰天雪地，寒风刺骨。不是内力高深的人，已然经受不住了。
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"xshan",
		"westup" : __DIR__"xshan2",
        ]));

	set("cost", 5);
	set("bing_can", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
