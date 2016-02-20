//Cracked by Roath
// Room: /d/heimuya/dangpu.c
// fear 1999/12/08 

inherit ROOM;

void create()
{
        set("short", "当铺");
        set("long", @LONG
这是镇上的一家当铺，柜台上摆着一个牌子(paizi)，
柜台后面分别陈列着各式武器(weapon)、护具穿戴(armor)、
药物(drug)、书藉(book)、和其它各式杂物(misc)的柜子。
柜台后坐着白老板，一双精明的眼睛上上下下打量着你。
LONG
        );
        set("no_beg",1);
		set("no_sleep_room", "1");
        set("item_desc", ([
                "paizi" : "公平交易\n",
        ]));
        set("objects", ([
                __DIR__"npc/bai" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"northstreet1",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}

