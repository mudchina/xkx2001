//Cracked by Roath
// group bwdh/room kantai north
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"

void create() {
    set("short", "北看台");
    set("long", @LONG
这里是比武场的北看台。现在已经是人声鼎
沸，群雄议论纷纷，都在猜测哪个团队能折桂。
四周有些桌子(desk)。
LONG
    );
    set("exits", ([
        "south"  : __DIR__"square",
        "west"  : __DIR__"kantai_w4",
        "east"  : __DIR__"kantai_e4",
    ]));
    create_kantai();
    setup();
}

void init() {
    init_kantai();
}
