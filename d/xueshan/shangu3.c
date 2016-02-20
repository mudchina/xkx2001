//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大雪山山谷");
        set("long", @LONG
一个宽大山谷, 群山环绕, 山顶上全是白闪闪的积雪, 山谷南方有两个山洞。
LONG
        );
        set("exits", ([
                "enter" : __DIR__"dycave",
		"north" : __DIR__"wangyou",
        ]));


	set("cost", 3);
	set("bing_can", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
