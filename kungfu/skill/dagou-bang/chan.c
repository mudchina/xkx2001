//Cracked by Roath
// chan.c 打狗棒法「缠」字诀
// fear 12/99 changed success rate and added random to target busy time 

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        if( weapon->query("skill_type") != "stick" )
                return notify_fail("你手中无棒，如何使得打狗棒法「缠」字诀？！\n");

        if( me->query_temp("ban",1) )
                return notify_fail("你已在使用绊字诀！\n");

        if( (int)me->query_skill("force") < 100 )
                return notify_fail("你的内功修为不够火候，使用不了「缠」字诀。\n");
        
        if( me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("你所用的内功与打狗棒的气路相悖！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够！\n");
                
        if( (int)me->query_skill("stick") < 100 )
                return notify_fail("你的打狗棒法不够娴熟，不会使用「缠」字诀。\n");

        if( target->is_busy() ) {
                me->add("neili", -10);
                me->add("jingli", -5);
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        }

        msg = CYN "$N使出打狗棒法「缠」字诀，幻出连山棒影，将$n吞没！\n";
        me->add("neili", -80);
        me->add("jingli", -20);

        if( ((random(me->query("combat_exp")/10000) * (int)me->query_skill("stick") ) > 
        (((int)target->query("combat_exp")/5000) * ((int)target->query_skill("parry")/2 + (int)target->query_skill("dodge")/2))/4) ) {

                msg += "结果$p被$P缠了个手忙脚乱，一时无法还招进攻！\n" NOR;
                target->start_busy( (int)me->query_skill("stick") /(30+random(10)));
        } else {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(1+random(3));
        }
        message_vision(msg, me, target);

        return 1;
}
