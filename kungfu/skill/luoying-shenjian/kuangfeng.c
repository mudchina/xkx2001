//Cracked by Roath
//kuangfeng.c 狂风绝技 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int strike, extra, kick, power;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("狂风绝技只能对战斗中的对手使用。\n");
	
	if ( me->query_temp("weapon") )
                return notify_fail("狂风绝技必须空手方可施展。\n");
	
  	if( me->query_skill_mapped("strike") != "luoying-shenjian" )
                return notify_fail("你所用的并非落英神剑掌，不能与旋风扫叶腿配合施展狂风绝技");

	if( me->query_skill_prepared("strike") != "luoying-shenjian" )
                return notify_fail("你所备的并非落英神剑掌，不能与旋风扫叶腿配合施展狂风绝技");

	if( me->query_skill_mapped("kick") != "xuanfeng-saoye" )
		return notify_fail("你所用的并非旋风扫叶腿，不能与落英神剑掌配合施展狂风绝技！\n");

	if( me->query_skill_prepared("kick") != "xuanfeng-saoye" )
                return notify_fail("你所备的并非旋风扫叶腿，不能与落英神剑掌配合施展狂风绝技！\n");

        if( me->query_skill_mapped("force") != "bitao-xuangong")
                return notify_fail("你所用的内功与「狂风绝技」心法相悖！\n");

	if( me->query_skill("bitao-xuangong", 1) < 80 )
		return notify_fail("你的碧涛玄功火候未到，无法施展狂风绝技！\n");

	if( me->query_skill("kick") < 135 )
		return notify_fail("狂风绝技需要精湛的旋风扫叶腿配合，方能有效施展！\n");

	if( me->query_skill("strike") < 135 )
		return notify_fail("你落英神剑掌修为不足，还不会使用狂风绝技！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用狂风绝技！\n");

		  if( me->query("jingli") <= 200 )
					 return notify_fail("你的精力不够使用狂风绝技！\n");

	message_vision(HIG "$N一声长啸，脸上青气大盛，欺近$n身去，三招落英神剑掌后紧接着三招旋风扫叶腿！\n出手快捷无伦，如同天风海雨般向$n袭来，正是桃花岛的狂风绝技。" NOR, me, target);

	strike = me->query_skill("strike")/6;
	kick = me->query_skill("kick")/6;
	power = strike + kick;
	extra = (power*3/2 + random(power*2))/2;

   if(extra > 300 ) extra =300;

	me->add_temp("apply/attack", extra);
	me->prepare_skill("kick");

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->prepare_skill("strike");

	me->prepare_skill("kick" , "xuanfeng-saoye");

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -100-random(power*3));
	me->add("jingli", -50-random(power*3));

	me->prepare_skill("strike", "luoying-shenjian");

	me->start_busy(1 + random(2));


	me->add_temp("apply/attack", -extra);
	return 1;
}
