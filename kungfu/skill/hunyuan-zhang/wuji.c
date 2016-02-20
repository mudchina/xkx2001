//Cracked by Roath
// wuji.c 混元无极

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("混元无极只能对战斗中的对手使用。\n");

	if( me->query_temp("wuji") )
		return notify_fail("你已在使用混元无极了！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("空手才能施展混元无极！\n");

	if( me->query_skill_mapped("strike") != "hunyuan-zhang" )
		return notify_fail("你所用的并非混元掌，不能施展混元无极！\n");

	if( me->query_skill_prepared("strike") != "hunyuan-zhang" )
                return notify_fail("你所备的并非混元掌，不能施展混元无极！\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("你所用的并非紫霞功，施展不出混元劲！\n");

	if( me->query_skill("force") < 140 )
		return notify_fail("你的紫霞功火候未到，无法施展混元劲！\n");

	if( me->query_skill("strike") < 135 )
		return notify_fail("混元无极需要精湛的混元掌方能有效施展！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用混元无极！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用混元无极！\n");	

	if( me->query_skill_prepared("cuff") == "pishi-poyu" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("cuff");
        }

	message_vision(MAG "\n$N运起紫霞功，全身泛起丝丝紫气，紧接着翻掌劈出一股气劲，无声无息地涌向$n！\n\n" NOR, me, target);
	me->set_temp("wuji", 1);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -150);
	me->add("jingli", -100);

	if( me->query_temp("restore") ) me->prepare_skill("cuff", "pishi-poyu");

	return 1;
}
