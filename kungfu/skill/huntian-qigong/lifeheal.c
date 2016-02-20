//Cracked by Roath
// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 40 )
		return notify_fail("你的混天气功修为不够！\n");

	if( target->query("id") == me->query("id") )
		return notify_fail("你不能为自己疗伤！\n");

	if( !living(target) )
                return notify_fail("太迟了，你要治疗的人已经死了！\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"已经受伤过重，经受不起你的真气震荡！\n");

	message_vision(
		HIY "$N运起内功，手掌按在$n后心命门，将真气输入$n体内....\n"
		"不久，$N浑身大汗淋漓，显得十分疲倦。\n"
                "只见$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -150);
	me->add("qi", -50);
	me->set("jiali", 0);

	return 1;
}
