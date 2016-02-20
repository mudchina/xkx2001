//Cracked by Roath
// tuwu.c 金蛇吐雾

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon1, weapon2;
	int tqi;

	weapon1 = me->query_temp("weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target || !target->is_character() || target->query("race") != "人类" )
		return notify_fail("你要偷袭谁？\n");

	if( environment(target)->query("no_fight") && !wizardp(me) )
		return notify_fail("在这里你不能施展「金蛇吐雾」使用暗器偷袭！\n");

	if( me->query_skill("throwing") < 100 )
		return notify_fail("你在金蛇锥法修为还不够，不能施展「金蛇吐雾」使用暗器偷袭！\n");

	if( me->query_skill("force") < 100 )
		return notify_fail("你的内功修为火候未到，劲力不足以施展「金蛇吐雾」发射暗器偷袭！\n");

	if( me->query("max_neili") <= 500 )
		return notify_fail("你的内力修为不足，劲力不足以施展「金蛇吐雾」发射暗器偷袭！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够，劲力不足以施展「金蛇吐雾」发射暗器偷袭！\n");

	message("vision", HIR "\n突然间"+me->name()+"对着"+target->name()+"一扬手施展「金蛇吐雾」，"+weapon1->name()
		+"无声无息地电闪至"+target->name()+"身前！\n\n" NOR, environment(target), ({target, me}) );
	me->add("neili", -100);

	tell_object(me, "你施展「金蛇吐雾」偷袭"+target->name()+"。\n");

	tqi = target->query("max_qi");

	if( random(me->query("combat_exp")) < random(target->query("combat_exp")) ) {
		tell_object(target, "你突然发现"+me->name()+"发出"+weapon1->name()+"向你偷袭！\n");
		message_vision("可是$p看破了$P的企图，避了开去。\n", me, target);
		weapon1->add_amount(-1);
//		me->add("neili", -15);
		if( target->query("qi")*100 / tqi <= 80 ) target->kill_ob(me);
		else if( !target->is_fighting(me) ) target->fight_ob(me);
		return 1;
	}

	if( objectp(weapon2 = target->query_temp("weapon")) ) {
	    if (me->query_str() >= target->query_str()) {
		switch ( random(2) ) {
		   case 0:
			message_vision("$N射出的"+weapon1->name()+"撞击上$n的"+weapon2->name()+"，擦出点点火星。\n", me, target);
			message_vision("$N猛然觉得虎口大震，手中的"+weapon2->name()+"脱手飞上半空！\n", target);
			weapon1->add_amount(-1);
			weapon2->move(environment(me));
			break;
		   case 1:
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			break;
		}
	    }			
	    else COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
	else COMBAT_D->do_attack(me, target, me->query_temp("weapon"));		

//	me->add("neili", -15);
	
	if( target->query("qi")*100 / tqi <= 80 ) target->kill_ob(me);
        else if( !target->is_fighting(me) ) target->fight_ob(me);

	return 1;
}
