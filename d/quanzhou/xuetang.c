//Cracked by Roath
// xuetang.c 学堂
// qfy Nov 7, 1996.

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "学堂");
        set("long", @LONG
这是城里的一所学堂，城中的子弟便在此上课。学堂里的柜子里摆满了书
籍。教书先生便是响誉泉州的欧阳詹先生。
LONG
        );

        set("exits", ([
                "east" : __DIR__"gtxiang",
        ]));

	set("objects",([
                __DIR__"npc/ouyang" : 1,
        ]));

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/朱", 0);
        return 1;
}
