//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
你走在一条走廊上，从东边飘来一股酥油的香味，北边是一座楼阁。
LONG
        );
        set("exits", ([
                "west" : __DIR__"sengshe",
                "north" : __DIR__"jingang",
                "east" : __DIR__"chufang",
		"northup" : __DIR__"hongdian",
	"south" : __DIR__"yanwu",
        ]));


	set("cost", 1);
        setup();
        replace_program(ROOM);
}
