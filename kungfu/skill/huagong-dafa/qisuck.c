//Cracked by Roath
// qisuck.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;
	int dmg;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || target == me
	|| target->query("id") == "mu ren"
	|| target->query("id") == "shangshan"
	|| target->query("id") == "mengzhu"
	|| target->query("id") == "fae" )
		return notify_fail("你要吸取谁的真气？\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过真气！\n");

	if( objectp(me->query_temp("weapon")) && me->query_skill("huagong-dafa",1) < 45)
		return notify_fail("你的化功大法功力不够，必须空手才能施用化功大法吸人真气！\n");

	if( !me->is_fighting() || !target->is_fighting() || !living(target) )
		return notify_fail("你必须在战斗中才能吸取对方的真气！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 30 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的真气。\n");

	if( (int)me->query("neili",1) < 10 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("qi") < (int)target->query("max_qi") / 5
	 || (int)target->query("jingli") < (int)target->query("max_jingli") / 5 )
		return notify_fail( target->name() +
			"已经真气涣散，你已经无法从他体内吸取真气了！\n");

	message_vision(
		HIB "$N突然诡异的一笑，双手一扬，拇指对准$n的掌心按了过来！\n\n" NOR,
		me, target );

	if( !target->is_killing(me) ) target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
	dp = target->query_skill("force") + target->query_skill("dodge") + target->query_kar();
		  sp *= me->query("combat_exp")/1000;
		  dp *= target->query("combat_exp")/1000;

	me->set_temp("sucked", 1);

	if( random(sp+dp) > dp )
	{
		tell_object(target, HIR "你突然觉得全身真气自手掌奔涌而出，四肢无力，再也使不出劲来！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的真气自手掌源源不绝地流了进来。\n" NOR);
		message_vision(
			HIR "$N觉得全身真气自手掌奔涌而出，四肢无力，再也使不出劲来！\n\n" NOR,
			target );

		me->add("qi", (int)me->query_skill("force") );

		if( target->query("combat_exp") >= me->query("combat_exp")/2 )
			me->add("combat_exp",1);

		me->start_busy(random(2));
		target->start_busy(random(2));
		me->add("neili", -(int)me->query_skill("force")/6);
		me->add("jingli", -5);

		dmg = random( me->query_skill("force")/100 )* me->query("neili");
		if( dmg > 2000) dmg=2000;
		if( dmg <300) dmg=300;
		dmg = random(dmg);
		target->receive_damage("qi", dmg, me );
		target->receive_wound("qi", random(dmg), me);

		COMBAT_D->report_status(target);

		call_out("del_sucked", 1, me);
	}
	else
	{
		message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
		me->add("jingli", -5);
		me->start_busy(2);
		call_out("del_sucked", 1+random(2), me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
