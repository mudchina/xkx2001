//Cracked by Roath
// longxiang 龙象之力
// kane 25/01/99

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, org, extra;
        string num;

        if( target != me ) 
                return notify_fail("你只能用龙象般若功来运龙象之力。\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("max_neili") < 2000  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("shielded") ) 
                return notify_fail("你已经在运护体神功了。\n");

        if( (int)me->query_temp("longxiang") )
                return notify_fail("你已经在运龙象之力了。\n");

        if( (int)me->query_skill("longxiang-banruo", 1) < 120)
                return notify_fail("你的龙象般若功火侯不够！\n");

        skill = me->query_skill("longxiang-banruo", 1);
        org = me->query_str();
        extra = skill/20;
        num = chinese_number(extra);
        me->add("neili", -300);

        message_vision(
        HIR"$N口中默念大明六字真言，手结摩利支天愤怒印，运起"+num+"龙"+num+"象之力！\n" +
        HIW"$N脚下砂石下陷，遽然出现了一个大坑！\n"
        NOR, me);

        me->add_temp("apply/armor_vs_force", extra*8);
	me->add_temp("apply/attack", extra*8);
        me->add_temp("apply/strength",  extra*4);
        me->add_temp("apply/speed", extra);
        me->add_temp("apply/defense",  -extra*2);
        me->add_temp("apply/armor", -extra*2);

        me->set_temp("longxiang", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, extra :), skill/3);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor_vs_force", -amount*8);
	me->add_temp("apply/attack", -amount*8);
        me->add_temp("apply/strength", -amount*4);
        me->add_temp("apply/speed", -amount);
        me->add_temp("apply/defense",  amount*2);
        me->add_temp("apply/armor", amount*2);
        me->delete_temp("longxiang");
        tell_object(me, MAG"你的龙象之力运行完毕，将内力收回丹田。\n"NOR);
}
