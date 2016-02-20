//Cracked by Roath
// group bwdh/room 04
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIG"西偏厅"NOR);
    set("long", @LONG
这里是比武场的西偏厅，空旷的大厅是一个很好的热身地方。
LONG
    );
    set("exits", ([
        "north" : __DIR__"room_03",
        "east"  : __DIR__"room_13",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
