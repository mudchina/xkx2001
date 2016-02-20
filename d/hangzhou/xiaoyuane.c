//Cracked by Roath
// /d/hangzhou/xiaoyuane.c
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{       set("short", "小院");
        set("long", @LONG
这里是镖局的后院，用来寄放客户的镖货。平时空着便是众镖头和趟子手休  
闲的去处，也是练功的场所。最近总镖头从少林寺俜请了几名高僧来指点镖局子  
上下好几百人的武功，这儿便显得热闹万分，时常通宵达旦。
LONG);
        set("exits", ([ /* sizeof() == 3 */
                "east" :  __DIR__"xiaoyuanee",
                "west" : __DIR__"xiaoyuan", 
        ]));

        set("objects", ([
                __DIR__"npc/zhu" : 1,
        ]));

	set("cost", 1);
	set("no_clean_up", 1);

        set("outdoors", "hangzhou");
        setup();
}

/*
void init()
{
        object me = this_player();
        int cost;

        if( me->query_condition("lmjob") && interactive(me) ) {
                cost = 20000 / ( (int)me->query_con() + 2 * (int)me->query("int") );
                me->receive_damage("jing", cost + random(cost));
                me->receive_damage("jingli", cost + random(cost));

                message_vision("\n几位镖头上前向$N行礼，争先恐后地向$N请教武功。\n", this_player());
                me->start_busy(1 + random(cost/10));
        }
        add_action("do_dazuo", "dazuo");
}

int do_dazuo(string arg)
{
        object me = this_player();
        mixed busy;

        if( busy = me->query_busy() ) {
                if (intp(busy)) me->start_busy(busy+1);
                return notify_fail("你现在正忙着！\n");
        }

        return 0;
}

int valid_leave(object me, string dir)
{
        if( me->query_condition("lmjob") ) {
                me->apply_condition("lmjob", 0);
                me->delete_temp("lmjob");
                message_vision("\n$N对身旁的镖头们说道：我有点急事，下次再教你们吧。\n", me);
        }

        return ::valid_leave(me, dir);
}
*/
