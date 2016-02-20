//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
空空荡荡一个山洞，倒也还算干净，尽头摆了一张石床。
LONG
        );
        set("exits", ([
                "out" : __DIR__"shangu3",
        ]));
	set("objects", ([
                __DIR__"obj/yuyi": 1,
	]));

	set("sleep_room",1);
	set("cost", 1);
        setup();
	replace_program(ROOM);
}
