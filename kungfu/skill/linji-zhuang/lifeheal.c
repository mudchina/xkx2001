//Cracked by Roath
// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target || target == me )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( !living(target) )
                return notify_fail("太迟了，你要治疗的人已经死了！\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") == (int)target->query("max_qi") )
		return notify_fail( target->name() +
			"已经康复，不需你协助运功疗伤了！\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 10 )
		return notify_fail( target->name() +
			"已经受伤过重，经受不起你的真气震荡！\n");

	message_vision(
		HIY "$N伸手搭上$n命门大穴，不疾不徐地将真气输入$n体内....\n"
		"不久，$N头顶便如蒸笼一般不绝有丝丝白气冒出。\n"
                "只见$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -100);
	me->set("jiali", 0);

	return 1;
}
