//Cracked by Roath
// pojian.c 独孤九剑「破索式」
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
		return notify_fail("破索式只能对战斗中的对手使用。\n");

	if( !objectp(weapon = target->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip" )
		return notify_fail("破索式只能对用长鞭、拂尘的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
		
	if( (int)me->query_skill("dugu-jiujian", 1) < 60 )
		return notify_fail("你的独孤九剑修为不够，还未学成「破索式」。\n");

        if( me->query("neili") <= 100 )
                return notify_fail("你的内力不够！\n");

	msg = CYN "$N剑势突然变得窒郁如举千斤，企图以独孤九剑的「破索式」缠住$n的"+weapon->query("name")+"。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "结果$p的"+weapon->query("name")+"被$P的剑势引开，脱手飞出。\n" NOR;
		weapon->move(environment(me));
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
