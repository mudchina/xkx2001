//Cracked by Roath
// liuchu.c 雪花六出
// maco :不开放的perform，code简陋，绝不足以学习！

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int speed, damage, sword;

        weapon = me->query_temp("weapon");

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("雪花六出攻击只能对战斗中的对手使用。\n");

        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何施展「雪花六出」？\n");

        if( me->query_skill("xueshan-jian",1) < 100 )
                return notify_fail("你的雪山剑法修为未到，施展不了「雪花六出」！\n");

        if( me->query("max_neili") <= 1200 )
                return notify_fail("你的内力修为不足，无法施展「雪花六出」。\n");

        if( me->query("neili") <= 400 )
                return notify_fail("你的内力不足，无法施展「雪花六出」。\n");

        if( me->query("jingli") <= 400 )
                return notify_fail("你的精力不足，无法施展「雪花六出」。\n");

        damage = me->query_skill("xueshan-jian")/6;
        speed = (me->query_skill("xueshan-jian")+me->query_skill("sword") )/240;
	me->add("neili", -100);
	me->add("jingli", -50);
	
	me->add_temp("xuehua", 1);
	me->add_temp("apply/speed", speed);
        me->add_temp("apply/attack", damage);
        me->add_temp("apply/damage", damage/2);
        
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
	me->add_temp("apply/speed", -speed);
        me->add_temp("apply/attack", -damage);
        me->add_temp("apply/damage", -damage/2);
	me->delete_temp("xuehua");
	me->start_busy(1);
        return 1;
}
