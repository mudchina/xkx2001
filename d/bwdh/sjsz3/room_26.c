//Cracked by Roath
// group bwdh/room 26
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIR"正厅"NOR);
    set("long", @LONG
这里是比武场的正厅，杀气越来越浓了。远处传来
极低微的呼吸声，偶尔有人影一闪而过。你似乎感觉到
有几双眼睛在对你窥视。
LONG
    );
    set("exits", ([
        "north"     : __DIR__"room_25",
        "west"      : __DIR__"room_28",
        "east"      : __DIR__"room_17",
		  "south"     : __DIR__"room_27",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
