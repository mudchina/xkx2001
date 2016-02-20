//Cracked by Roath
// juezhao.c 祭血神刀 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill1, skill2, enfor, amount, shen1, shen2, nei_loss, qi_loss;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("祭血神刀只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if( weapon->query("skill_type") != "blade" )
                return notify_fail("你手中无刀，如何使得祭血神刀？\n");

	if( me->query_str() < 25 )
		return notify_fail("你的臂力不足以使用血刀绝招！\n");

	if( me->query_skill("longxiang-banruo", 1) < 80
	&& me->query_skill("xiaowuxiang", 1) < 80)
		return notify_fail("你的龙象般若功火候未到，无法施展祭血神刀！\n");

	if( me->query_skill_mapped("force") != "longxiang-banruo"
	&& me->query_skill_mapped("force") != "xiaowuxiang")
                return notify_fail("你所用的内功与祭血神刀的气路相悖！\n");

	if( me->query_skill("xue-dao", 1) < 120 )
		return notify_fail("你的血刀火侯未到，不会使绝招！\n");

	if( me->query("neili") <= 800 )
		return notify_fail("你的内力不够使用祭血神刀！\n");

	message_vision(HIR "$N突然倒转刀锋对着自己额头猛砍一刀，暴喝一声：看招！溅满鲜血、泛着血光的刀身却又仿佛化成一片血海，笼罩住$n的身影。\n\n" NOR, me, target);

   // take into account both attacker and victem's shen
	shen1 = 0 - me->query("shen");
	shen2 = me->query("shen");
	skill1 = me->query_skill("force");
	skill2 = me->query_skill("blade");
	enfor = me->query("jiali");
	amount = 80 + (skill1+skill2)/30 + ((shen1/1500)+random(shen2/2000))/10;
   // higher the power, higher cost 
    // adjust for the new combatd limit of 400
	if (amount > 400)
		amount = 400;
	nei_loss = 0 - amount - 200;
	qi_loss = 0 - amount/20 - 20;

	me->add_temp("apply/attack", amount);
	me->add_temp("apply/damage", amount);
	me->add_temp("apply/dodge",  amount);
	me->set("jiali", 50+enfor);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->start_busy(1+random(2));
	me->add("neili", nei_loss);
	me->add("jingli", -50);
	me->add("eff_qi", qi_loss);
	me->set("jiali", enfor);
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/dodge", -amount);

	return 1;
}
