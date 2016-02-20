//Cracked by Roath
// group bwdh/room kantai west
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"
#include "entrance.h"

void create() {
    set("short", "西看台");
    set("long", @LONG
这里是比武场的西看台。参加比武的选手也从
这里入场。现在已经是人声鼎沸，群雄议论纷纷，
都在猜测哪个团队能折桂。四周有些桌子(desk)。
LONG
    );
    set("exits", ([
        "north" : __DIR__"kantai_w2",
        "south" : __DIR__"kantai_w3",
//        "east"  : __DIR__"west_xiangfang",
    ]));
    create_kantai();
    setup();
}

void init() {
    object me = this_player();

    init_kantai();
    if ( me->query("id") == "sheying shi")
        destruct(me);
    else if ( me->query("sjsz/fighting") )
        out_xiangfang();
}

int valid_leave(object me, string dir) {
    if( dir == "east" ) {
        if(wizardp(me) || me->query("sjsz/entrance") == "west" ) {
            go_xiangfang();
            return ::valid_leave(me, dir);
        }
        else
            return notify_fail("只有指定的参赛选手才可以去那里。\n");
    }            

	return ::valid_leave(me,dir);
}