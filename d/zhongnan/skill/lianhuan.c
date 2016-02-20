//Cracked by Roath
///kungfu/skill/chunyang-quan/lianhuan.c 连环三招
// sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int str, dex, skill;
	string weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("连环三招只能对战斗中的对手使用。\n");


	if( objectp(me->query_temp("weapon")) )
		return notify_fail("连环三招需空手才能施展！\n");

	if( me->query_skill_mapped("cuff") != "chunyang-quan" )
		return notify_fail("你所用的并非纯阳拳，不能施展连环三招！\n");

	if( me->query_skill_prepared("cuff") != "chunyang-quan" )
                return notify_fail("你所备的并非纯阳拳，不能施展连环三招！\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("你所用的并非玄门先天功，施展不出连环三招！\n");

	if( me->query_skill("force") < 140 )
		return notify_fail("你的玄门先天功火候未到，无法施展连环三招！\n");

	if( me->query_skill("cuff") < 135 )
		return notify_fail("连环三招需要精湛的纯阳拳方能有效施展！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用连环三招！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用连环三招！\n");


	message_vision(HIR "$N怒喝一声，拚尽全力，突然闪电般攻出连环三招！\n\n" NOR, me, target);

	str = me->query_str();
	//me->add_temp("apply/strength", str/2);
	me->add_temp("apply/attack",100);
	me->set_temp("lianhuan",1);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	//me->add_temp("apply/strength", -str/2);
	//me->add_temp("apply/dexerity", -dex/2);
	me->add_temp("apply/attack",-100);
	me->delete_temp("lianhuan");

	me->add("neili", -150);
	me->add("jingli", -100);
	me->start_busy( 1+random(2) );

	return 1;
}


