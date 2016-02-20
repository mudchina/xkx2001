//Cracked by Roath
//石板路 /d/shenlong/shibanlu
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "青石板路");
        set("long", @LONG
一条幽静的青石板路，一头通向大厅，一头通向竹林，路旁放着几盆花
卉，开着菊花、蔷薇等，煞是艳丽。南面是仙福居，北面是伙房。
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
                "south" : __DIR__"xianfuju",
                "north" : __DIR__"huofang",
                "west" : __DIR__"dating",
                "east" : __DIR__"zhulin1",
        ]));

        set("cost", 1);

        setup();
        replace_program(ROOM);
}

