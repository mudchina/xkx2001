//Cracked by Roath

// /kungfu/skill/hamagong/powerup.c
// modified by sdong to increase some qi and cut some attack 10/25/98
// modified by maco to add hmg_lv litmit and change msg 2/1/2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill,l;

	if( target != me )
		return notify_fail("你只能用蛤蟆功功来提升自己的战斗力。\n");

	if( (int)me->query_skill("hamagong",1) < 40)
		return notify_fail("你的蛤蟆功修为未到，无法有效提升出招威力。\n");
	if( (int)me->query("neili") < 100  )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -200);

	message_vision(WHT"只见$N蹲在地下，双手弯与肩齐，宛似一只大青蛙般作势相扑，口中发出老牛嘶鸣般的咕咕之声，时歇时作。\n" NOR, me);

	me->add_temp("apply/attack", skill/4);
	me->add_temp("apply/damage", skill/4);

	if(me->query("family/family_name") == "白驼山" )
	{
		me->set( "eff_qi",me->query("eff_qi")+skill*4 );
		me->add("qi",skill);
	}
///	me->add_temp("apply/dodge",  skill/2);
	me->set_temp("powerup", 1);

	//me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	l = skill /5;

	call_out("remove_effect",l,me,skill/4);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	if(me->query_temp("apply/attack") < 0 )me->set_temp("apply/attack",0);
	me->add_temp("apply/damage", - amount);
	if(me->query_temp("apply/damage") < 0 )me->set_temp("apply/damage",0);

	if( me->query("family/family_name") == "白驼山" && me->query("eff_qi") > me->query("max_qi") )
	{
		me->set( "eff_qi",me->query("eff_qi")-amount*16 );
		if(me->query("eff_qi")<=100)me->set("eff_qi",100);
	}
//	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	message_vision(HIR "只见$N的蛤蟆功运行完毕，将内力收回丹田。\n" NOR, me);
}