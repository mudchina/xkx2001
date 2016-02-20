//Cracked by Roath
// group bwdh/room 15
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
        "south"     : __DIR__"room_16",
        "southwest" : __DIR__"room_25",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
