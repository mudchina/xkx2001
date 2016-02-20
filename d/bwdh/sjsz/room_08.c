//Cracked by Roath
// group bwdh/room 08
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIG"东偏厅"NOR);
    set("long", @LONG
这里是比武场的东偏厅，空旷的大厅是一个很好的热身地方。
LONG
    );
    set("exits", ([
        "west"      : __DIR__"room_05",
        "east"      : __DIR__"ezoulan",
	 ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
