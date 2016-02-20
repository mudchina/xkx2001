//Cracked by Roath
// Room: /city/mipu.c
// YZC 1996/11/13 
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "米铺");
        set("long", @LONG
你好不容易挤了进来，看见两个衙役正在这里维持次序。店里的老板好像不
在，只有一个不吭声的伙计正低着头给一些人打米。大家的表情好像都很气愤，
但是又显得无可奈何，只有一边打着米，一边嘴里唠叨着。正上方挂了一面牌子
(paizi)。向北就可以出米铺到象南街上了。
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiangnanjie",
        ]));

        set("item_desc", ([
                "paizi" : "今由于各处大米涨价，故每斗在原基础上上涨白银一两。\n",
        ]));

        set("objects", ([
                "/d/forest/npc/cl_mi" : 1,
                "/d/forest/npc/cl_huoji" : 1,
        ]));

        set("cost", 0);
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ling;

        if( me->query_temp("bangs/shoptime") ) {
                me->delete_temp("bangs/shoptime");
                me->set_temp("apply/short", 
                ({ HIR + "长乐帮" + "帮众"NOR + me->query("name")+"("+capitalize(me->query("id"))+")" }));
                if( ling = present("bang ling", me) )
                        ling->delete("job");
               message_vision("$N趁人不注意，溜出店门。\n", me);
        }

        return ::valid_leave(me, dir);
}

