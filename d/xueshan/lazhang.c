//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "拉章别院");
        set("long", @LONG
这里是拉章活佛和贡唐仓国师的住所，院内小巧玲珑，雕梁画栋。
拉章活佛和贡唐仓国师通常就在这里授徒。
LONG
        );
        set("exits", ([
                "north" : __DIR__"houyuan2",
        ]));
	set("objects", ([
                __DIR__"npc/lazhangfo" : 1,
        ]));

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
