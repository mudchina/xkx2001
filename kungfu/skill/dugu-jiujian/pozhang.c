//Cracked by Roath
// pojian.c 独孤九剑「破掌式」
// qfy July 5, 1996.

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("破掌式只能对战斗中的对手使用。\n");

	if( weapon = target->query_temp("weapon"))
		return notify_fail("破掌式只能对空手的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
		
	if( (int)me->query_skill("dugu-jiujian", 1) < 70 )
		return notify_fail("你的独孤九剑修为不够，还未学成「破掌式」。\n");

        if( me->query("neili") <= 100 )
                return notify_fail("你的内力不够！\n");

	msg = CYN "$N运剑使出独孤九剑的「破掌式」，灵动变幻，狂风暴雨般地猛攻$n各处破绽。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "$p无从招架，亦退避不得，结果连中数剑受伤。\n" NOR;
		target->add("eff_qi",-(random((int)me->query_skill("dugu-jiujian"))*2));
		target->start_busy( (int)me->query_skill("sword") / 28 );
	} else {
		msg += "可是$p看破了$P的剑路，还招挡开。\n" NOR;
		me->start_busy(1 + random(3));
	}
	message_vision(msg, me, target);
	me->add("neili", -25);
	me->add("jingli", -10);

	return 1;
}
