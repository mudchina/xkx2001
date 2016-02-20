//Cracked by Roath
// Room: /city/dangpu.c
// YZC 1995/12/04 
// Mantian remove Ssy south room path since mirror and @us ppl can't access wiz tree 05/12/2001

inherit ROOM;

void create()
{
        set("short", "当铺");
        set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上
摆着一个牌子(paizi)，柜台后面有五个大柜子，分别陈列着各式武器(weapon)、
护具穿戴(armor)、药物(drug)、书藉(book)、和其它各式杂物(misc)。柜台后
坐着唐老板，一双精明的眼睛上上下下打量着你。
LONG
        );
        set("no_beg",1);
        set("no_sleep_room", "1");
        set("item_desc", ([
                "paizi" : "公平交易\n",
        ]));
        set("objects", ([
                __DIR__"npc/tang" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"nandajie1",
//              "south" : "/u/ssy/paimai",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}
