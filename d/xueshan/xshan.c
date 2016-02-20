//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大雪山");
        set("long", @LONG
这儿遍地冰雪，你眼前白皑皑的一片。从东边爬上来的，心跳开始加速。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"shankou",
		"southup" : __DIR__"xshan1",
        ]));


	set("cost", 3);
	set("bing_can", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
