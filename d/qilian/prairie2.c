//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大草原");
        set("long", @LONG
你渐渐地能望见西面天边下的一座座小山，再往西走，很快
就走出草原了。
LONG
        );
        set("exits", ([
                "west" : "/d/xueshan/shixia",
                "east" : __DIR__"prairie",
        ]));
	set("objects", ([
                "/d/qilian/npc/boy": 2,
        ]));
	set("resource/grass", 1);
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
