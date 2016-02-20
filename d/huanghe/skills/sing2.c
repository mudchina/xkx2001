//Cracked by Roath
// fanchang.c 梵唱
// changed by Aln for special lama npcs

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;



int exert(object me, object target)
{
	object obj, weapon;
	int ap, dp; 

        seteuid(getuid());

        if( userp(me) )
                return notify_fail("it is only for npcs.\n");
        if( me->is_busy() )
                return notify_fail("you are busy now.\n");

	if( !objectp(weapon = me->query_temp("weapon"))
        ||  (string)weapon->query("id") != "lubo" )
                return notify_fail("你未执法器，不能凝神梵唱。\n");

	if( !objectp(obj = present("kulou guan", me))
        ||  !obj->query("equipped") )
		return notify_fail("你未顶骷髅冠，不能凝神梵唱。\n");

	if( !objectp(obj = present("rentou lian", me))
        ||  !obj->query("equipped") )
                return notify_fail("你未戴人头链，不能凝神梵唱。\n");

	if( !living(target) )
                return notify_fail("看清楚一点，那并不是活物。\n");

	if( target->query("race") != "人类" )
		return notify_fail(target->query("name") + "听不懂你的咒语！\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("necromancy", 1) < 30 )
                return notify_fail("你的降伏法功力不够！\n");

	if( (int)me->query_skill("lamaism", 1) < 30 )
                return notify_fail("你的密宗心法功力不够！\n");

	if( (int)me->query_skill("longxiang-banruo", 1) < 30 )
		return notify_fail("你的龙象般若功功力不够！\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能唱。\n");

	if( target->query_temp("cursed", 1) || target->query_temp("block_msg/all", 1))
		return notify_fail("此人已被降伏！\n");

	if( (int)me->query_temp("curser") ) 
                return notify_fail("你降伏着另一各人！\n");

	me->add("neili", -50);
	me->receive_damage("jingli", 50);

	message_vision(
		BLU "$N摇头晃脑，口中背诵大乘佛经，夹杂以密宗六字咒。声音阴阳顿挫，有起有伏，暗含音律。\n" NOR, me);

	tell_object(target,  "你觉得那密咒比鬼哭还难听，脑袋里一团絮乱，眼前一堆鬼影在乱跳，胸气阻塞，四肢无力，混然欲睡。\n");
		
	ap = (int)me->query("neili") + (int)me->query("max_neili") +
             (int)me->query_skill("necromancy", 1) * 10 +
             (int)me->query_skill("lamaism", 1) * 10;
	dp = (int)target->query_skill("force") * 10;

	ap *= (int)me->query("combat_exp")/1000 + 1;
        dp *= (int)target->query("combat_exp")/1000 + 1;

        if( random(ap + dp) > dp ) {
		tell_object(target, HIR"\n你只觉得眼前的一切离你慢慢远去，你的魂魄似要出窍，不再由你主宰。\n"NOR);

                target->start_busy(2 + random(2));
		target->set_temp("cursed", 1);
                target->set_temp("yield", 1);
	    //  target->set_temp("block_msg/all", 1);
		me->set_temp("curser", 1);

		message_vision(HIR"\n$N突然开始两眼发直，呆呆地望着前方。\n"NOR, target);

                remove_call_out("del_sung");
                call_out("del_sung", 3 + random(3), me, target);
	} else{
	        me->start_busy(1 + random(3));
	        if( !target->is_killing(me->query("id")) ) 
                        target->kill_ob(me);
	}

        return 1;
}

void del_sung(object me, object target)
{
        if( target ) {
        if (target->query_temp("cursed", 1))
		target->delete_temp("cursed");
	if (target->query_temp("block_msg/all", 1))
	        target->delete_temp("block_msg/all");
	if (target->query_leader() ) 
                target->set_leader(0);
        if( target->query_temp("yield") )
                target->delete_temp("yield");

        message_vision("$N慢慢地清醒过来，魂魄又回到了自己身体上。\n", target);
        }

        if( me ) {
        if ( me->query_temp("curser") )
        	me->delete_temp("curser");
        }
}

