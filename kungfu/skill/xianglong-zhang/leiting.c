//Cracked by Roath
// leiting 雷霆降龙
// qfy Oct 7, 1996
// kane Oct, 22, 1998
// sdong , 7/30/1999

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;
	int skill, enfor, amount;

	enfor = me->query("jiali");

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("雷霆降龙只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("雷霆降龙只能空手运用。\n");

	if( me->query_str() < 30 )
		return notify_fail("你的臂力不足以施展雷霆降龙！\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("你所用的并非混天气功，无法加力施展雷霆降龙！\n");

	if( me->query_skill("force") < 135 )
		return notify_fail("你的混天气功火候未到，无法施展雷霆降龙！\n");

	if( me->query_skill("strike") < 135 )
		return notify_fail("你降龙十八掌修为不足，还不会使用雷霆降龙！\n");

	if( (me->query("neili") - (150+enfor+enfor/2)) <= 350 )
		return notify_fail("你的内力不够使用雷霆降龙！\n");

        if( me->query_temp("xianglong",1) )
                return notify_fail("你正在使用内功，无法试用雷霆降龙！\n");

	if( me->query_temp("sanhui_busy") )
		return notify_fail("你微一运劲，只觉胸中气息沉浊，无力出掌！\n");

	if ( me->query_condition("hyz_damage") )
		return notify_fail("你身受混元劲内伤，提不起真力施展雷霆降龙！\n");

	message_vision(HIR "\n$N仰天大喝，双手立刃雷霆般地对着$n劈出，掌风卷动无数飞砂走石，天地为之变色！\n\n" NOR, me, target);

	skill = me->query_skill("force");
	amount = skill/3;

	me->add_temp("apply/attack", amount);
	me->add_temp("apply/strike", amount/3);
	me->add_temp("apply/damage", amount);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -amount*3);
	me->add("jingli", -amount);

	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/strike", -amount/3);

	me->start_busy(1+random(2));
	return 1;
}
