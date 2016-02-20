//Cracked by Roath
//suxing.c 玉女素心
//by sdong

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;
	int bili,original,dodge,skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("玉女素心只能对战斗中的对手使用。\n");


	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return notify_fail("你所用的并非玉女心经，无法施展玉女素心！\n");

	if( me->query_skill("yunu-xinjing", 1) < 60 )
		return notify_fail("你的玉女心经火候未到，无法施展玉女素心！\n");


	if( me->query_skill("sword") < 135 )
		return notify_fail("你的玉女剑法修为不足，还不会使用玉女素心！\n");

	if( me->query("neili") <= 400 )
		return notify_fail("你的内力不够使用玉女素心！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用玉女素心！\n");

	if( (int)me->query_temp("suxin") ) 
		return notify_fail("你已经发动了玉女素心！\n");


	message_vision(HIR "$N清啸一声，运起玉女素心内诀，将内力源源不断地注入"+(me->query_temp("weapon"))->query("name")+ HIR "，身法也突然加快！\n\n" NOR, me);

	skill = me->query_skill("yunu-jianfa", 1);
	original = me->query_skill("force")/2;
	bili = me->query_str();
	dodge = me->query_dex();

	me->add_temp("apply/strength", bili/2);
	me->add_temp("apply/dexerity", dodge/2);
    me->add_temp("apply/damage", 150);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

    me->add_temp("apply/damage", -150);
	me->add_temp("apply/armor", original);
    me->add_temp("apply/damage", original);
	me->start_busy(1+random(2));
	me->add("neili", -150);
	me->add("jingli", -100);
	me->set_temp("suxin", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, bili,original,dodge :), 5);
//	me->start_busy(3);


	return 1;
}


void remove_effect(object me, int bili, int amount,int dodge)
{
	me->add_temp("apply/strength", - bili/2);
	me->add_temp("apply/dexerity",-dodge/2);
	me->add_temp("apply/armor",-amount);
    me->add_temp("apply/damage", -amount);

	me->delete_temp("suxin");

	tell_object(me, "你缓缓吸了一口气，收回玉女素心，内力又回到丹田。\n");
}
