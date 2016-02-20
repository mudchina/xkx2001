//Cracked by Roath
// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( (int)target->query("eff_qi")*5 > (int)target->query("max_qi")*4 )
                return notify_fail("no need now.\n");
        if( userp(me) )
                return notify_fail("only used by lamas.\n");

	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( !living(target) )
                return notify_fail("太迟了，你要治疗的人已经死了！\n");

	if( me->is_busy() )
		return notify_fail("you are busy now\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"已经受伤过重，经受不起你的真气震荡！\n");

        COMMAND_DIR"std/halt"->main(me);

	message_vision(
		HIY "$N运起内功，手掌按在$n后心命门，将真气输入$n体内....\n"
		"不久，$N浑身大汗淋漓，显得十分疲倦。\n"
                "只见$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	target->receive_curing("qi", 200 + random(200));
        target->receive_heal("qi", 200 + random(200));

	me->add("neili", -50);
	me->add("qi", -50);
        me->start_busy(1);

	return 1;
}
