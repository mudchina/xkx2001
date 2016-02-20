//Cracked by Roath
// pojian.c 独孤九剑「破气式」
// qfy July 5, 1996.

#include <ansi.h>
private int qi_damage_300(object me, object target);
private int qi_damage_220(object me, object target);
private int qi_damage_150(object me, object target);

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;
	int dugu_skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("破气式只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
		
	if( (int)me->query_skill("dugu-jiujian", 1) < 90 || (int)me->query("max_neili") < 400 )
		return notify_fail("你的独孤九剑或内力修为不够，还未学成「破气式」。\n");

        if( me->query("neili") <= 100 )
                return notify_fail("你的内力不够！\n");

	dugu_skill = me->query_skill("dugu-jiujian",1);

	msg = CYN "$N潜运独孤九剑「破气式」，运气贯剑使其由利返钝，毫无花俏地直刺$n的丹田。\n";
	message_vision(msg, me, target);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {

		if ( dugu_skill >= 150 ) {
                        qi_damage_150(me, target);
                }

		if ( dugu_skill >= 220 && me->query("dugu/poqi") ) {
			qi_damage_220(me, target);
		}

		if ( dugu_skill >= 300 && me->query("dugu/poqi") ) {
			qi_damage_300(me, target);
		}

		target->start_busy( (int)me->query_skill("sword") / 28 );

	} else {
		msg = "可是$p看破了$P的剑路，还招挡开。\n" NOR;
		me->start_busy(1 + random(3));
		message_vision(msg, me, target);
	}

	me->add("neili", -25);
	me->add("jingli", -10);

	return 1;
}

#include "/kungfu/skill/dugu-jiujian/poqi.h"
