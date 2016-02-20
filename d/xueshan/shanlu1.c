//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
你走在一山路上，四周有一座座小山丘。
LONG
        );
        set("exits", ([
                "east" : __DIR__"shixia",
		"south" : __DIR__"shanlu4",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
