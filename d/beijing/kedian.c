//Cracked by Roath
// Room: /d/beijing/kedian.c

#include <ansi.h>
#include "/d/beijing/beijing_defs.h"
inherit ROOM;


void create()
{
        set("short", HIC"诚意客栈"NOR);
        set("long", @LONG
这是京城中一家普通的客栈，由于靠近天桥，生意非常兴隆。外地游客
多选择这里落脚，店小二里里外外忙得团团转，接待着南腔北调的客人。上
面挂着一个牌子(paizi)。
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("item_desc", ([
                "paizi" : "楼上雅房，每夜二十两白银。\n",
        ]));

        set("objects", ([
                __DIR__"npc/kedian_xiaoer" : 1,
        ]));

        set("exits", ([
                "up" : __DIR__"kedian2",
                "north" : __DIR__"tianqiao",
        ]));

        setup();
	set("no_fight", 0);

        "/clone/board/beijing_b"->foo();
}

int valid_leave(object me, string dir)
{
        string id;
        int i;

        if(me == present("xiao er"))
                return ::valid_leave(me, dir);

        if(objectp(present("xiao er", environment(me)))) {
                if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

                if ( me->query_temp("rent_paid") && dir != "up" )
                return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");
        }

        return ::valid_leave(me, dir);
}

void init()
{
    if (random(3) == 1) 
        HELPER->clonehere_with_limit(this_object(), "/d/beijing/obj/jiaozi", 4);
}

