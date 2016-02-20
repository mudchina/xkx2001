//Cracked by Roath
// /d/wanshou/mishi.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"
inherit ROOM;

void create()
{

        set("short", "密室");
        set("long", @LONG
这是山庄三庄主金甲狮王史叔刚养伤的地方，屋内布置简单，
西侧靠窗的地方放着一张床，是史叔刚调养休息的地方，房间一角
有一个药炉，一个小僮守在一旁正在为负伤的三庄主煎药。
LONG
        );

        set("exits", ([
                "west" : __DIR__"zhenting",
        ]));

        set("objects", ([
                __DIR__"npc/shugang" : 1,
        ]));

        set("cost", 0);

        setup();
        replace_program(ROOM);

}

