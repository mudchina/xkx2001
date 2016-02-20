//Cracked by Roath
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        object *inv;
        int i, mmn, tmn, mexp,texp,m1,m2;
	int a;

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
		mmn =  me->query("max_neili");
		tmn =  target->query("max_neili");
		mexp = (int)me->query("combat_exp")/1000;
		texp = (int)me->query("combat_exp")/1000;
		m1 = me->query_skill("liumai-shenjian");
		m2 = me->query("max_qi");
		a = (int)(m1*5+m2)/2;
         message_vision(HIR
"$N双手姆指向前猛地一摁，两道无形剑气直袭$n的身影。\n\n" NOR, me,target);

if(random(mmn+mexp)  > random(tmn+texp) ) {
if (mexp > texp) 
{

target->add("qi",(-a));

target->receive_wound("qi", (m1*2));
me->add("max_neili", (-3));
tell_object(target, BLU "你只觉两道劲气扑面，霍的胸口一阵剧痛。\n"NOR);
tell_object(me, BLU "你使出全身功力向$n点出两指，顿时感到一阵虚脱。\n"NOR);
        me ->start_busy(1+random(3));
  }
else
{
target->add
("qi",-(a*2/3));      
target->receive_wound("qi", (m1*2));
me->add("max_neili", (-3));
tell_object(target, BLU "你只觉两道劲气扑面，霍的胸口一阵剧痛。\n"NOR);
tell_object(me, BLU "你使出全身功力点出两指，顿时感到一阵虚脱。\n"NOR);
                 
        me ->start_busy(1+random(3));
  }      
}
       else 
        {
message_vision(HIR
"$n赶紧向後跃开数丈，躲开$N的攻击。\n\n" NOR, me, target);

        }

        me->start_busy(1+random(3));
        me->add("max_neili", -1);
        return 1;
}

