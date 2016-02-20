//Cracked by Roath
// group bwdh/room 18
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIM"东厅"NOR);
    set("long", @LONG
这里是比武场的东厅，四周静悄悄的。空气中已经弥漫
者一股杀气，使你感到不寒而栗。
LONG
    );
    set("exits", ([
        "north"     : __DIR__"room_17",
        "south"     : __DIR__"room_19",
        "east"      : __DIR__"room_07",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
