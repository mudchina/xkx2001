//Cracked by Roath

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("你只能使自己的经脉倒转。\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("reverse") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -200);

	message_vision(
	HIY "只见$N口中叫道「差尔刺呼，哈虎」，忽做头下脚上之形，双手撑地，蹦来蹦去。\n" NOR, me);
	//突然一个筋斗，头下脚上，运起欧阳锋所授的功夫，经脉逆行
	me->add_temp("apply/dodge",  skill/2);
	me->set_temp("reverse", 1);

	call_out("remove_effect", skill/2 ,me,skill/2);

//	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
//	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("reverse");
	tell_object(me, "你的经脉倒转运行完毕，经脉回复一如往常。\n");
}
