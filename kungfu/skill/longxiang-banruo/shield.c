//Cracked by Roath
// shield.c 护体神功

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("你只能用龙象般若功来运护体神功。\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("shielded") ) 
		return notify_fail("你已经在运功中了。\n");

        if( (int)me->query_temp("longxiang") )
                return notify_fail("你已经在运龙象之力了。\n");

	if( (int)me->query_skill("longxiang-banruo", 1) < 20)
		return notify_fail("你的龙象般若功火侯不够！\n");

	skill = me->query_skill("force");
	me->add("neili", -100);

	message_vision(
	MAG "$N长吸一口气，运起护体神功，身上衣衫缓缓涨起，一股真流遍流全身。\n" NOR, me);

	me->add_temp("apply/armor",  skill/2);
	me->add_temp("apply/defense",  skill/2);
	//me->add_temp("apply/armor_vs_force", skill/2)

	me->set_temp("shielded", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/2);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	//me->add_temp("apply/armor_vs_force", - amount)
	me->add_temp("apply/armor", - amount);
	me->add_temp("apply/defense", - amount);
	me->delete_temp("shielded");
	tell_object(me, "你的护体神功运行完毕，将内力收回丹田。\n");
}
