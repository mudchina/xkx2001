//Cracked by Roath
//tonggui.c //同归
//by sdong

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me, object target);

int perform(object me, object target)
{
	string weapon;
	int skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("同归剑法只能对战斗中的对手使用。\n");

	if( me->query_temp("tonggui",1) )
		return notify_fail("你已在使用同归剑法！\n");

	if( me->query("eff_qi",1) > me->query("max_qi",1) * 2 / 3 )
		return notify_fail("你好端端的，跟人家同归干什么？\n");


	if( me->query_skill_mapped("force") != "xiantian-gong" )
		return notify_fail("你所用的并非先天功，无法施展同归剑法！\n");

	if( me->query_skill("xiantian-gong",1) < 100 )
		return notify_fail("你的先天功火候未到，无法施展同归剑法！\n");


	if( me->query_skill("sword") < 135 )
		return notify_fail("你的全真剑法修为不足，还不会使用同归剑法！\n");

	if( me->query("neili") <= 100 )
		return notify_fail("你的内力不够使用同归剑法！\n");
	if( me->query("jingli") <= 150 )
		return notify_fail("你的精力不够使用同归剑法！\n");


	weapon = me->query_temp("weapon");
	skill =  ( me->query_skill("quanzhen-jian")
		+ me->query_skill("force") ) / 6;

	me->set_temp("apply/attack", me->query_temp("apply/attack",1)+skill);
	me->set_temp("apply/damage", me->query_temp("apply/damage",1)+skill);
	me->set_temp("apply/parry", me->query_temp("apply/parry",1)-skill/2);
	me->set_temp("apply/dodge", me->query_temp("apply/dodge",1)-skill/2);

	message_vision(HIR "$N怒吼一声，剑招突变，身形晃动，剑光闪闪，全都指向敌人要害，端的是招招狠，剑剑辣，竟自不加防守，一味凌厉进攻！\n\n" NOR, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->set("neili", 0);
	me->add("jingli", -100);
	me->set_temp("tonggui",1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target:),skill/3 );
	return 1;
}

int remove_effect(object me, object target)
{
	me->set_temp("apply/attack", 0);
	me->set_temp("apply/damage", 0);
	me->set_temp("apply/parry", 0);
	me->set_temp("apply/dodge", 0);
	me->delete_temp("tonggui");
	message_vision(
	HIG "\n$N吸了一口气，将内力收回丹田，剑招也恢复正常！\n\n" NOR, me);

	return 0;
}

