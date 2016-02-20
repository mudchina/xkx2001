//Cracked by Roath
// 化功护体
// wsky 05/03/2k

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的内力不足使用护体神通。\n");

        if( (int)me->query("max_neili") < 2000  )
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query_temp("hua") )
                return notify_fail("你已经在运用化功大法护住周身大穴。\n");

        if( (int)me->query_skill("huagong-dafa", 1) < 150)
                return notify_fail("你的化功大法修为不够！\n");

        if( (int)me->query("canhua") != 1)
                return notify_fail("你的化功大法修为不够！\n");


        skill = me->query_skill("huagong-dafa", 1);
 
        me->add("neili", -500);

        message_vision(HIB"$N面色陡变，两只手交叉并与胸前，潜运内功，将化功大法功力布满全身。\n"NOR, me);

        me->add_temp("apply/parry",  skill/3);
        me->set_temp("hua", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/10);

        if( me->is_fighting() ) me->start_busy(random(2)+1);

        return 1;
}

void remove_effect(object me, int skill)
{
        me->delete_temp("hua",1);
        me->delete_temp("apply/parry",  skill/2);                       
        message_vision(HIY"$N微觉疲惫，只好将护体的内力收回。\n"NOR,me);
}

