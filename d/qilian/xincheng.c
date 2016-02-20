//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "新城");
        set("long", @LONG
这是兰州以西的新城，是西北驻军的囤粮之处。粮仓连绵，
设有重兵防卫，寻常老百姓是不让靠近的。
LONG
        );
        set("exits", ([
                "east" : __DIR__"guandao2",
                "north" : __DIR__"guandao3",
                "south" : __DIR__"prairie",
        ]));
        set("objects", ([
		"/d/xingxiu/npc/bing" : 4,
	]));

	set("cost", 1);
    set("outdoors", "qilian-shan");
	setup();
}
