//Cracked by Roath
// Room: /d/heimuya/kedian.c
// fear 1999/12/08
#include <ansi.h>
inherit ROOM;

// Marz added indecent or inapproapriate id check here :
string* Banned_id = ({
        "ufk",
        "none",
});


void create()
{
        set("short", HIC"平定客店"NOR);
        set("long", @LONG
这是平定州的一间小客店，店前挑出一个白布招子，
写着“平定客店”四个大字。店小二里里外外团团忙着
接待着南来北往的客人。墙上挂着一个牌子(paizi)。
西面是一间马厩。
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"weststreet1",
                "up" : __DIR__"kedian2",
                "west" : __DIR__"majiu",
        ]));

        setup();
//      "/clone/board/kedian_b"->foo();
//      "/clone/board/jiangpai_b"->foo();
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
