//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大雪山口");
        set("long", @LONG
这里已经到了藏边，大雪山的山口。大雪山又叫岷山，位于川
藏之间，由于山势高峻，山顶有终年不化的积雪，故而得名。四下
毫无人迹，只有几只秃鹰在高处盘旋，俯视着茫茫雪山。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"shanlu7",
		"westup" : __DIR__"xshan",
        ]));
	set("objects", ([
                __DIR__"npc/tuying": 2,
        ]));

	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
