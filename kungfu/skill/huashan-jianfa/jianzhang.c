//Cracked by Roath
//jianzhang.c 剑掌五连环 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;
	object weapon1;
	int    lvl1, lvl2, amount;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("剑掌五连环只能对战斗中的对手使用。\n");

	weapon1 = me->query_temp("weapon");
        if( !objectp(weapon1) || weapon1->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何使得剑掌五连环？\n");

	if( me->query_skill_mapped("strike") != "hunyuan-zhang" )
		return notify_fail("你所用的并非混元掌，不能与华山剑法配合施展剑掌五连环！\n");

	if( me->query_skill_prepared("strike") != "hunyuan-zhang" )
                return notify_fail("你所备的并非混元掌，不能与华山剑法配合施展剑掌五连环！\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
		return notify_fail("你所用的并非紫霞功，无法施展剑掌五连环！\n");

	if( me->query_skill("zixia-gong", 1) < 60 )
		return notify_fail("你的紫霞功火候未到，无法施展剑掌五连环！\n");

	if( (lvl1=me->query_skill("strike")) < 100 )
		return notify_fail("剑掌五连环需要精湛的混元掌配合，方能有效施展！\n");

	if( (lvl2=me->query_skill("sword")) < 100 )
		return notify_fail("你华山剑法修为不足，还不会使用剑掌五连环！\n");

	amount = (lvl1+lvl2) / 15;

	if ( amount < 40 ) amount = 40;
	if ( amount > 80 ) amount = 80;

	if( me->query("neili") <= amount*4 )
		return notify_fail("你的内力不够使用剑掌五连环！\n");
	if( me->query("jingli") <= amount*2 )
		return notify_fail("你的精力不够使用剑掌五连环！\n");

	if( me->query_skill_prepared("cuff") == "pishi-poyu" ) {
		me->set_temp("restore", 1);
		me->prepare_skill("cuff");
	}

	weapon = me->query_temp("weapon");

	me->add_temp("apply/damage", amount);
	me->add_temp("apply/attack", amount*2);
	me->add_temp("apply/dodge", amount*2);

	message_vision(HIR "\n突然间$N身形电闪，瞬间逼近$n，剑掌交替中向$n奋力击出三剑两掌！\n\n" NOR, me, target);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->wield();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->wield();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->start_busy(1+random(3));
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/attack", -amount*2);
	me->add_temp("apply/dodge", -amount*2);
	me->add("neili", -amount*3);
	me->add("jingli", -amount*2);
	if( me->query_temp("restore") ) me->prepare_skill("cuff", "pishi-poyu");

	return 1;
}
