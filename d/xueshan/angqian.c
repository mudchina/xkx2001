//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "昂欠一楼");
        set("long", @LONG
这里是各代活佛的居所，正中是嘉木活佛的宝座，殿内悬挂着别致精
巧的宫灯及各种色彩艳丽的唐卡，显得庄严豪华。楼上是法王的寝宫，寻常
僧侣不得准许，是不能上去的。出了昂欠就是后院了。
LONG
        );
        set("exits", ([
                "up" : __DIR__"angqian2",
                "south" : __DIR__"houyuan",
        ]));
	set("objects", ([
                __DIR__"npc/jiamu" : 1,
        ]));

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
