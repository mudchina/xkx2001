//Cracked by Roath
// Room: 皇城当铺
// Ssy 

inherit ROOM;

void create()
{
        set("short", "皇城当铺");
        set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上
摆着一个牌子(paizi)，柜台后面有五个大柜子，分别陈列着各式武器(weapon)、
护具穿戴(armor)、药物(drug)、书藉(book)、和其它各式杂物(misc)。柜台后坐
着当铺老板，一双精明的眼睛上上下下打量着你。
LONG
        );
        set("no_beg",1);

        set("item_desc", ([
			   "paizi" : "公平交易，童叟无欺。\n",
        ]));
        set("objects", ([
			 __DIR__"npc/dpboss" : 1,
        ]));
        set("exits", ([
		       "west" : __DIR__"fuchengdajie_s",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}

