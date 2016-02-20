#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("你只能用八荒六合功来提升自己的战斗力。\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);

	message_vision(
	HIR "$N凝神息气，运起八荒六合唯我独尊功，只见一股轻烟缭绕周身。\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/5);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "你的八荒六合唯我独尊功运行完毕，将内力收回丹田。\n");}
}
