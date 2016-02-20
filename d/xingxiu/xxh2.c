//Cracked by Roath
// Room: /d/xingxiu/xxh2.c
// Jay 3/18/96

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。
这里左右两厢通向星宿海的深处，北边是星宿派总舵——日月洞   。
洞口的墙由於风沙的剥蚀凸凹不平，墙根前堆积了很厚的流沙，一些
芦苇和红柳条支支楞楞地露出头来。边上立着一个牌子(paizi)。
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([
             "north" : __DIR__"riyuedong",
             "south" : __DIR__"xxh1",
             "northeast" : __DIR__"xxh3",
             "northwest" : __DIR__"xxh4",
        ]));

        set("item_desc", ([
                "paizi" : "星宿海福地，日月洞洞天。\n",
        ]));

        //set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        set("cost", 2);

        setup();

	call_other("/clone/board/xingxiu_b", "???");
        //"/clone/board/xingxiu_b"->foo();

}
