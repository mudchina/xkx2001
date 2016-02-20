//Cracked by Roath
// Room: /city/kedian.c
// YZC 1995/12/04
#include <ansi.h>
inherit ROOM;

// Marz added indecent or inapproapriate id check here :
string* Banned_id = ({
        "ufk",
        "none",
});


void create()
{
        set("short", HIC"车马店"NOR);
        set("long", @LONG
一家低档的车马客栈，建筑相当陈旧，很不起眼，不过由于价钱低廉，又是
在北门的交通要道上，三教九流多选择这里落脚，生意也相当不错，你也可以在
这里打听到当地的风土人情。墙上挂着一个牌子(paizi)。
LONG
        );

//      set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"nandajie",
		"up" : __DIR__"kedian2",
        ]));

        setup();

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

                if ( me->query_temp("rent_paid") && dir == "east" )
                return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");
        }

        id = (string)me->query("id");
        for (i = 0; i < sizeof(Banned_id); i++)
        {
        if (id == Banned_id[i])
        {
                me->set("startroom", "/d/death/block");
                me->move("/d/death/block");
                return notify_fail("嘿嘿，看你能跑到哪里去！！\n");
        }
        }

        return ::valid_leave(me, dir);
}
