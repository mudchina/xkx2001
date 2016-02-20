//Cracked by Roath
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        object *inv;
        int i, mmn, tmn, mexp,texp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + 
"目前正自顾不暇，放胆攻击吧。\n");
                
        if( (int)me->query_skill("liumai-shenjian", 1) < 120 )
                return notify_fail("你的六脉神剑修为不够。\n");
        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够！\n");

       
        me->add("neili", -300);
mmn =  me->query("max_neili");
tmn =  target->query("max_neili");
mexp = me->query("combat_exp")/1000;
texp = target->query("combat_exp")/1000;

 message_vision(HIR
"$N双手点点戳戳，无形气剑纵横\n\n"NOR, me,target);
 if( (mmn+mexp)  > (tmn+texp) ) {

inv = all_inventory(target);
        for(i=0; i<sizeof(inv); i++)
            if( inv[i]->query("weapon_prop/damage"))
                destruct(inv[i]);
       message_vision(HIR 
"$N双手点点戳戳，便逼得$n纵高伏低，东闪西避。突然间拍的一声响，$n手中兵刃\n" 
NOR, me,target);
 message_vision(HIR"为$N的无形气剑所断，化为寸许的二三十截，飞上半空，斜阳映照，闪出点点白光。\n\n"
NOR, me,target);

	 tell_object(target, BLU 
"你只觉手上一震，手中兵刃已断成了数十截！\n" NOR);
       
                target->start_busy(1+random(1));
        }
        else 
        {
        message_vision(HIY "$p赶紧向後跃开数丈，躲开$P的攻击。\n" NOR, 
me, target);
        }
        me->start_busy(1+random(3));
        return 1;
}

