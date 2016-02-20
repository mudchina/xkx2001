//Cracked by Roath
// neiheal.c
// qfy Nov 12, 1996.

#include <ansi.h>

int exert(object me, object target)
{
	int mode, duration1, level, duration2;
	
	if( !target || target == me ) return 0;
	if( target == me ) mode = 1;
	else mode = 2;

   	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("战斗中无法运功疗伤！\n");

   	if ( mode == 1 ) {
		if ( (int)me->query_skill("zixia-gong", 1) < 20 ) 
			return notify_fail("你的紫霞功修为还不够。\n");

		if( (int)me->query("neili") < 50 )
			return notify_fail("你的真气不够。\n");

		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

		write( HIW "你全身放松，坐下来运起紫霞功疗伤。\n" NOR);
		message("vision",
			HIW + me->name() + "坐下疗伤，突然面上紫气大盛吐出瘀血，脸色看起来好多了。\n" NOR,
			environment(me), me);

        	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
		me->add("neili", -50);
		me->set("jiali", 0);
	}	
	else {
		if ( (int)me->query_skill("zixia-gong", 1) < 50 )
			return notify_fail("你紫霞功的造诣太浅，不能为他人化解混元无极劲内伤！\n");

		if( (int)me->query("max_neili") < 300 )
			return notify_fail("你的内力修为不够。\n");

		if( (int)me->query("neili") < 150 )
			return notify_fail("你的真气不够。\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() +"已经受伤过重，经受不起你的真气震荡！\n");

		if( !living(target) )
			return notify_fail("此人已昏死或死了，不能救治！\n");

		message_vision(MAG"$N坐下运起紫霞功，连连拍按$n各处命门大穴，徐徐地将真气输入$n体内....\n"
				  "不久，$N额头上大汗淋漓，头上紫气蒸腾，显得十分疲倦。\n"
				  "只见$n吐出一口瘀紫红的瘀血，脸色却显得十分苍白。\n" NOR, me, target );

		target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
		target->add("qi", 10 + (int)me->query_skill("force")/3 );
		if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

		me->add("neili", -150);
		me->set("jiali", 0);
	}

	return 1;
}
