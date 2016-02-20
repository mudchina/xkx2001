//Cracked by Roath
// RYU 1/5/97
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "小木屋");
        set("long", @LONG
这是座普通的小木屋，可能一个猎人住在这里。里面陈设简单，一
张桌子，几把椅子，墙边有四张小木床，屋中央是个炉子，上面吊着的
一个铁水壶，水蒸气正缓缓的从壶嘴冒了出来，窗下有捆绳子。
LONG
        );
        set("exits", ([
        ]));


        setup();
        replace_program(ROOM);
}
