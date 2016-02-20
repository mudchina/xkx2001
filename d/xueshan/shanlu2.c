//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
你走在一山路上，四周有一座座小山丘。能遥望见西南方大雪山
的北麓。山前隐隐约约象是有一座寺院。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"shanlu6",
                "westup" : __DIR__"beilu",
        ]));
	set("objects", ([
		"/d/xueshan/npc/xiangke" : 1, 
	]));
	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
