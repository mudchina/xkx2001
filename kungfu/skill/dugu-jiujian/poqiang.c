//Cracked by Roath
// pojian.c 独孤九剑「破枪式」
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
		return notify_fail("破枪式只能对战斗中的对手使用。\n");

	if( !objectp(weapon = target->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff" ) {
	   if( !objectp(weapon = target->query_temp("weapon")) 
	   || (string)weapon->query("skill_type") != "club" ) {
	      if( !objectp(weapon = target->query_temp("weapon"))
	      || (string)weapon->query("skill_type") != "stick" ) {
		if( !objectp(weapon = target->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "halberd" ) {
		   if( !objectp(weapon = target->query_temp("weapon"))
		   || (string)weapon->query("skill_type") != "pike" )
		      return notify_fail("破枪式只能对用枪、棍、棒、杖的对手使用。\n");
		}
	      }
	   } 
	}

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
		
	if( (int)me->query_skill("dugu-jiujian", 1) < 50 )
		return notify_fail("你的独孤九剑修为不够，还未学成「破枪式」。\n");

        if( me->query("neili") <= 100 )
                return notify_fail("你的内力不够！\n");

	msg = CYN "$N一式独孤九剑「破枪式」，剑势灵巧地顺着"+weapon->query("name")+"削落，划向$n的五指。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "结果$p唯有舍弃"+weapon->query("name")+"，向后跃开丈许，先求自保。\n" NOR;
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
