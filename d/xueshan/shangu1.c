//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大雪山山谷");
        set("long", @LONG
山谷里遍地积雪，四周都是峭壁。只北面有一个出口，东面似乎有个山洞。
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"shangu",
                "east" : __DIR__"cave1",
        ]));
	set("objects", ([
                "/kungfu/class/xuedao/shengdi" : 1,
        ]));


	set("cost", 3);
	set("bing_can", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
