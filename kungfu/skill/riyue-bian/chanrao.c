//Cracked by Roath
// chanrao.c 天缠地绕

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
		return notify_fail("天缠地绕只能对战斗中的对手使用。\n");

	weapon = me->query_temp("weapon");
        if( weapon->query("skill_type") != "whip" )
                return notify_fail("你手中无鞭，如何使得天缠地绕？\n");
	if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够！\n");
	
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	msg = HIY "$N使出日月鞭法的天缠地绕诀，连挥数鞭，如黑龙般着地向$n的全身卷去！\n";

	me->add("neili", -100);
	me->add("jingli", -50);

	if( random(me->query("combat_exp")) > random(target->query("combat_exp")) ) 
	{
		msg += "结果$p被$P攻了个措手不及，浑身被漫天鞭影裹在其中！\n" NOR;
		target->start_busy( (int)me->query_skill("whip") / 30 );
	} 
	else 
	{
		msg += "可是$p看破了$P的鞭法去路，敏捷地闪了开去。\n" NOR;
		me->start_busy(1 + random(3));
	}

	message_vision(msg, me, target);

	return 1;
}
