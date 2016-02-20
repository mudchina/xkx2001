//Cracked by Roath
// changle/clxiaoting.c
// by aln

#define WOSHI   "/d/forest/clwoshi"
#define BANGZHU "/d/forest/npc/cl_situ"

inherit ROOM;

#include "/d/huanghe/changle/info_beauty.h";

void create()
{
        set("short", "小厅");
        set("long", @LONG
这是帮主及总管商讨机密大事的所在，正中是一张太师椅，门上
吊着半旧的红绸软帘。墙上附庸风雅地挂着几张山水字画，一望可知
均是俗手之作。窗前几盆菊花倒是十分繁茂。
LONG );

        set("exits", ([
		"south" : __DIR__"clzoulang2",
		"north" : __DIR__"clwoshi",
        ]));

        set("cost", 0);
        set("objects",([
                __DIR__"npc/cl_situ" : 1,
        ]));

        setup();
        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        string beauty;
        object ob, leader, ling, *inv;
        int bonus, record;

        if( dir != "north" )
                return ::valid_leave(me, dir);

        if( !(ob = present("situ heng", environment(me))) )
                return ::valid_leave(me, dir);

        if( !living(ob) )
                return ::valid_leave(me, dir);

        if( ob->is_fighting() || ob->is_busy() ) {
                message_vision("$N拦在$n面前，喝道：" + RANK_D->query_rude(me) + "不得无礼！没见帮主正忙着？\n", ob, me);
                return notify_fail("");
        }

        if( stringp(beauty = me->query_temp("bangs/beauty")) ) {
                inv = all_inventory(this_object());
                for(int i = 0; i < sizeof(inv); i++) {
                if( (string)inv[i]->query("name") == beauty
                && inv[i]->query_leader() == me ) {
                message_vision("$N在$n的头上弹了个清脆的脑崩儿，$n的脑门儿上立刻长出了个小臌包。\n", ob, me);
                return ::valid_leave(me, dir);
                }
                }
	}

        if( !userp(me) ) {
                beauty = (string)me->query("name");
                if( intp(bonus = info_beauty[beauty])
                &&  leader = me->query_leader() ) {
                if( userp(leader) && (string)leader->query_temp("bangs/beauty") == beauty ) {
                tell_object(leader, ob->name() + "说道：好！好！好！" + (string)ob->query("fam") + "上上下下几千人中数你最讨帮主的欢心！\n");
                leader->delete_temp("bangs/beauty");

                bonus = bonus * 25000 / (100000 + (int)leader->query("combat_exp"));
                record = bonus + random(bonus);
                leader->add("combat_exp", record);
                leader->add("shen", -record);
                write_file("/log/test/BangWomen",  sprintf("%s于%s时上贡%s得%s经验点\n", leader->query("name"), ctime(time()), beauty, chinese_number(record)));

                if( ling = present("bang ling", leader) ) {
                if( (string)ling->query("owner") == leader->query("id") )
                        ling->add("score", bonus/2 + random(bonus/2));
                }

                me->set_leader(0);

                remove_call_out("destroy_beauty");
                call_out("destroy_beauty", 1, me, leader);
                return ::valid_leave(me, dir);
                }
                }
	}

        message_vision("$N拦在$n面前，喝道：" + RANK_D->query_rude(me) + "不得无礼！后面是帮主的卧房。\n", ob, me);

        return notify_fail("");
}

void destroy_beauty(object me, object leader)
{
        object room, ob;

        if( !me ) return;

        if( !leader ) { destruct(me); return; } 

        room = environment(me);
        if( base_name(room) != WOSHI )
                 { destruct(me); return; }

        if( room != environment(leader) )
                 { destruct(me); return; }

        if( !(ob = present("shijian", room)) )
                 { destruct(me); return; }

        if( !living(ob) )
                 { destruct(me); return; }

        message_vision("$N对$n喝道：我要给这位小姐更衣，你快出去吧！\n", ob, leader);

        message_vision("$N飞起一脚将$n踢了出去。\n", ob, leader);
        leader->move(this_object());
        message("vision",
                leader->name() + "被人从卧房中踢了出来，狼狈不堪。\n",
                this_object(), ({leader}));

        destruct(me);
}
