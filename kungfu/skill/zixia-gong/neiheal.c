//Cracked by Roath
// neiheal.c
// qfy Nov 12, 1996.

#include <ansi.h>

int exert(object me, object target)
{
	int mode, duration1, level, duration2;

	if( target == me ) mode = 1;
	else mode = 2;

   	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("战斗中无法运功疗伤！\n");

   	if ( mode == 1 ) {
		if ( !(int)me->query_condition("hyz_damage") > 0 )
			return notify_fail("你并未受混元无极劲内伤！\n");

		if ( (int)me->query_skill("zixia-gong", 1) < 80 ) 
			return notify_fail("你紫霞功的造诣太浅，不能化解混元无极劲内伤！\n");

		if( (int)me->query("neili") < 150 )
			return notify_fail("你的真气不够。\n");

		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

		message_vision(MAG"$N盘膝坐下运动紫霞功，只见头上紫气腾腾，不吐出一口紫红的瘀血，脸色显得十分苍白。\n"NOR, me);
        	me->apply_condition("hyz_damage", 0);
        	me->add("neili", -100);
		me->receive_damage("qi", 100, "体力透支过度死了");
	}	
	else {
		if ( !(int)target->query_condition("hyz_damage") > 0 )
			return notify_fail("此人并未受混元无极劲内伤！\n");

		if ( (int)me->query_skill("zixia-gong", 1) < 100 )
			return notify_fail("你紫霞功的造诣太浅，不能为他人化解混元无极劲内伤！\n");

		if( (int)me->query("max_neili") < 600 )
			return notify_fail("你的内力修为不够。\n");

		if( (int)me->query("neili") < 250 )
			return notify_fail("你的真气不够。\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() +"已经受伤过重，经受不起你的真气震荡！\n");

		if( !living(target) )
			return notify_fail("此人已昏死或死了，不能救治！\n");

		message_vision(MAG"$N坐下运起紫霞功，连连拍按$n各处命门大穴，徐徐地将真气输入$n体内....\n"
				  "不久，$N额头上大汗淋漓，头上紫气蒸腾，显得十分疲倦。\n"
				  "只见$n吐出一口瘀紫红的瘀血，脸色却显得十分苍白。\n" NOR, me, target );

		tell_object(target,GRN"你感到一股与你一股真力在你五脏六腑间游走，渐渐地\n"
				      "在化解你的内伤，造成时麻时痒的感觉。\n"NOR);

		if( (int)target->query_skill("zixia-gong", 1) > 20 ) {
			tell_object(target,GRN"你混元无极劲内伤被化解了。\n"NOR);
			target->apply_condition("hyz_damage", 0);
			target->receive_damage("qi", 100, "体力透支过度死了");
			me->add("neili", -200);
			me->receive_damage("qi", 100, "体力透支过度死了");
		}
		else {
			level = me->query_skill("zixia-gong", 1);
			duration1 = target->query_condition("hyz_damage");
			duration2 = duration1 - me->query_skill("zixia-gong", 1) / 20;

			if ( duration2 < 0 ) duration2 = 0;

			target->apply_condition("hyz_damage", duration2);
			me->add("neili", -200);
			if ( target->query_condition("hyz_damage") > 0 ) {
				tell_object(me,"你发觉"+target->name()+"无法完全吸收你紫霞功的真力，看来得分几次治疗！\n");
				if( (int)target->query_skill("zixia-gong", 1) > 0 )
					tell_object(target,"你的紫霞功修为不够，无法与"+me->name()+"的真力融合，看来得分几次治疗！\n");
				else tell_object(target,"你内功心法与紫霞功大相径庭，无法与"+me->name()+"的真力融合，看来得分几次治疗！\n");
			}
			else tell_object(target,GRN"你混元无极劲内伤被化解了。\n"NOR);
			target->receive_damage("qi", 150, "体力透支过度死了");
			me->receive_damage("qi", 100, "体力透支过度死了");
		}
	}

	return 1;
}
