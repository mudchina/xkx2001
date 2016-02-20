//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条崎岖的山路，马队到了这里就不能在上去了。山路两旁杂草从
生，路开始越来越难走。
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"shanlu4",
		"southup" : __DIR__"shanlu6",
        ]));
	set("objects", ([
                __DIR__"npc/tuying": 1,
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
