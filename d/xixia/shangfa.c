//Cracked by Roath
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "赏罚堂");
        set("long", @LONG
一品堂纪律严明，凡有贪污受贿，无事生非，调戏民女之成员，都
会在这里受到应有的制裁。凡有巨功于一品堂的，都会在这里受到堂主
的赏赐和提拔。厅中悬条幅书道：赏罚分明。
LONG
        );
        set("exits", ([
        ]));


        setup();
        set("outdoors","xixia");
        replace_program(ROOM);
}
