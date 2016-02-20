//Cracked by Roath
// Room: /d/heimuya/zahuopu.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "杂货铺");
        set("long", @LONG
这里是家卖杂货的小铺子，里面摆满了各种式样的
货物，琳琅满目。墙上挂有一个陈旧的木牌(mupai)。
LONG
        );

        set("item_desc", ([
                "mupai": HIG"价钱公道，童叟无欺。\n"NOR,
        ]));

        set("exits", ([
                "north" : __DIR__"weststreet1",
        ]));

        set("objects", ([
                __DIR__"npc/shopkeeper": 1,
        ]));

        set("cost", 1);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}

