//Cracked by Roath
// group bwdh/room kantai south
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"

void create() {
    set("short", "南看台");
    set("long", @LONG
这里是比武场的南看台。现在已经是人声鼎
沸，群雄议论纷纷，都在猜测哪个团队能折桂。
四周有些桌子(desk)。
LONG
    );
    set("exits", ([
        "north" : __DIR__"square",
        "west"  : __DIR__"kantai_w5",
        "east"  : __DIR__"kantai_e5",
    ]));
    create_kantai();
    setup();
}


void init() {
    init_kantai();
}
