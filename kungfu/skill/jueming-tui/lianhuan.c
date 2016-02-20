//Cracked by Roath
//lianhuan.c 连环 perform

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	mapping fam;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("连环决只能对战斗中的对手使用。\n");

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "神龙教")
		return notify_fail("你非神龙教弟子，不能运本教神龙腿法！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正晕头转向，乘机进攻吧ⅵ\n");

	if( me->query_skill_mapped("strike") != "huagu-mianzhang" )
		return notify_fail("你所用的并非化骨绵掌，不能与决命连环腿配合施展！\n");

	if( me->query_skill_prepared("strike") != "huagu-mianzhang" )
                return notify_fail("你所备的并非化骨绵掌，不能与决命连环腿配合施展！\n");

	if( me->query_skill("dulong-dafa", 1) < 60 )
		return notify_fail("你的毒龙大法火候未到，无法施展连环决！\n");

	if( me->query_skill("kick", 1) <40)
		return notify_fail("连环腿需要精湛的基本腿法配合，方能有效施展！\n");

	if( me->query_skill("jueming-tui",1 ) <40)
		return notify_fail("你决命腿修为不足，还不会使用连环决！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用连环决！\n");

	if( (int)me->query("jingli") < 150 )
		return notify_fail("你的精神无法集中。\n");

	msg = HIY "\n 突然间$N身形腾空而起，凌空向$n奋力连踢几腿！\n" NOR;


	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") ) {

		target->start_busy( (int)me->query_skill("jueming-tui", 1) / 20 );
		damage = (int)me->query_skill("dulong-dafa", 1);
		damage = damage/2 + random(damage);

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		me->add("neili", -damage/10);

		if( damage < 40 ) msg += HIY"结果$n被$N的连环腿踢得晕头转向！ⅵ\n" NOR;
		else msg += HIR"结果$n被$N的连环腿踢中要害，「哇！」的一口鲜血喷涌而出！\n"NOR;
	}

	 else {
		msg += "可是$p看破了$P的企图，巧妙得躲了开去。\n" NOR;
		me->start_busy(1 + random(3));
	}
	message_vision(msg, me, target);

	return 1;
}

