//Cracked by Roath
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void remove_shaoze(object, object);

int perform(object me, object target)
{
        string msg;
        int skill, amount;
	object weapon;
	weapon = me->query_temp("weapon");

        skill  = (int)me->query_skill("liumai-shenjian", 1);

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("少泽剑只能对战斗中的对手使用。\n");

if( me->query_temp("weapon") )
                return notify_fail("你只能在空手时使用六脉神剑！\n");
        
if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够！\n");
       
 if( me->query_skill("liumai-shenjian", 1) < 120 )
                return 
notify_fail("你的六脉神剑火候未到，无法施展少泽剑！\n");

        if( target->is_busy() )

                return notify_fail(target->name() + 
"目前正自顾不暇，放胆攻击吧ⅵ\n");

        msg = HIY 
"$N左手小指连颤数下，刹那间只觉剑气满天！\n";

        me->start_busy(random(1));
        me->add("neili", -100);
        me->add("jingli", -50);

        if( random(me->query("combat_exp")) > 
random(target->query("combat_exp")) ) 
        { 
                msg +=
"$n顿时心中暗起恐畏之念，不禁留下几分功力自保！\n" NOR;

	me->set("krcg",3);
	me->set_temp("shaoze",1);
                remove_call_out("remove_shaoze");
                call_out("remove_shaoze", skill/10, me,target);


}
        else 
        {
                msg += "可是$n视若不见，手下丝毫不停。\n" NOR;
                me->start_busy(1 + random(2));
        }

        message_vision(msg, me, target);

        return 1;
}

void remove_shaoze(object me, object target) 
{
       
        me->delete_temp("shaoze");
	me->set("krcg",0);
        tell_object(me, target->name() + "的攻式逐渐加强了起来。\n");
        tell_object(target, "你觉得身前的剑气渐渐散去。\n");
}

