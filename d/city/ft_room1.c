//Cracked by Roath
// chu@xkx 7/27/98

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "内院");
        set("long", @LONG
你眼前突然一亮，此处竟别有天地，光线从米缸底部的一个小孔透入，照亮
了整个天井。正中央是一座假山，院落的西北角有一口井(well)，北面似乎是一
个议事堂。
LONG
        );
        set("exits", ([
                "out" : __DIR__"minwu1",
                "north" : __DIR__"ft_datang",
        ]));
        set("item_desc", ([
                "well" : "上面写着：“流香泉”。\n"
        ]));
        set("resource/water", 1);
        set("invalid_startroom", 1);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
