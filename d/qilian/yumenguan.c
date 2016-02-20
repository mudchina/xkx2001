//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "玉门关");
        set("long", @LONG
这是大西北的最外一道关隘，过了玉门关，就是西域，那里的居民多为碧
眼的胡人，“劝君更饮一杯酒，西出阳关无故人”，再往西去汉人就不多了。
LONG
        );
        set("exits", ([
                "east" : __DIR__"halahu",
                "south" : __DIR__"danshan",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
