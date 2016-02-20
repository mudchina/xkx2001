//Cracked by Roath
// Summer 9/12/96

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "紫柏坡");
        set("long", @LONG
紫柏坡在祈连山脉中是座小山峰，但风景绝佳。漫山小溪潺潺，有山鱼
悠游其中。周山盛开一种紫色山花，四季不谢，相传是由紫德真人所种，但
以讹传讹，得名紫柏，其实山上一颗柏树也没有。
LONG
        );

        if( !random(10) ) {
                set("objects", ([
                        "/d/changbai/npc/jiao2" : 1,
	        ]));
        }

        set("exits", ([
                "westup" : __DIR__"qitian",
                "northeast" : __DIR__"ailao",
		"east" : __DIR__"tieshi",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
