//Cracked by Roath
// caishen.h  采参

#include <ansi.h>

void init()
{
        this_player()->delete_temp("cbshen");
        add_action("do_search", "tan");
        add_action("do_search", "search");
        add_action("do_dig", "wa");
        add_action("do_dig", "dig");
}

int do_search(string arg)
{
        object me;
        int power;

        if( !arg || !(arg == "参" || arg == "人参") )
                return 0;

        me = this_player();

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙着。\n");

        if( me->query_temp("cbshen/参1") )
                return notify_fail("你不是已经找到人参了吗？\n");

        if( !present("suobo gun", me) )
                return notify_fail("你没有索拨棍，无法拨开灌木山草寻找人参！\n");

        if( (int)me->query("jingli") < 80 )
                return notify_fail("你太累了，先歇息一会儿吧。\n");

        me->add_temp("cbshen/times", 1);
        me->add("jingli", -40);
        me->start_busy(1);   

        if( query("count") < 1 && (int)me->query_temp("cbshen/times") > 30 )
		return notify_fail("你用索拨棍拨打着四周的灌木杂草，可是没发现有人参的踪迹！\n");

        message_vision("$N用索拨棍拨打着四周的灌木杂草，希望能从中发现人参的踪迹！\n", me);

        power = (int)me->query_temp("cbshen/times") * (int)me->query("kar");
        power *= query("count");

        if( random(power) > 100 ) {
                me->set_temp("cbshen/参1", 1);
                message_vision(HIG"\n$N用棍子不断的拨打着四周的山草，忽然发现杂草之中有一株人参！\n"NOR, me);
                write("你不禁高兴的跳了起来，高声喊道：棒——槌——！" +
                       "声音远远传了开去，在大山中回荡，久久不散！\n");
	}

        return 1;
}

int do_dig(string arg)
{
        object me, ob;

        if( !arg || !(arg == "参" || arg == "人参") )
                return 0;

        me = this_player();

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙着。\n");

        if( !(ob = present("lugu qianzi", me)) )
		return notify_fail("你没有鹿骨钎子，无法将人参从土中起出！\n");

        if( (int)me->query("jingli") < 80 )
                return notify_fail("你太累了，先歇息一会儿吧。\n");

        me->add("jingli", -60);
        me->start_busy(1);

        if( !me->query_temp("cbshen/参1") ) {
                message_vision("$N拿着鹿骨钎子使劲的挖着土，忽听嘎巴一声，钎子断为两截！\n", me);
                destruct(ob);
                return 1;
        }
 
        add("count", -1);
        ob = new(DRUG_D("cb_renshen"));
	ob->move(me);
 
        message_vision(HIY"$N从怀中掏出一把鹿骨钎子，小心翼翼的把人参从土中起出！\n"NOR, me);
        me->delete_temp("cbshen");

        return 1;
}


