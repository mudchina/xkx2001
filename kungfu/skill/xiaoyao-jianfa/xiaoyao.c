//Cracked by Roath
//xiaoyao
//by wsky, 20/09/00

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me);

int perform(object me, object target)
{
        string weapon;
        int skill, bonus;
	mapping myfam;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("逍遥连环只能对战斗中的对手使用。\n");

        if( me->query_temp("xiaoyao",1) )
                return notify_fail("你已在使用逍遥连环！\n");

        if( me->query_skill_mapped("force") != "shenghuo-xuanming" && me->query("id")!="wsky")
                return notify_fail("你所用的并非圣火玄冥功，无法施展逍遥连环！\n");

        if( me->query_skill("shenghuo-xuanming", 1) < 120 )
                return notify_fail("你的圣火玄冥功火候未到，无法施展逍遥连环！\n");

	if( me->query_skill_mapped("parry") != "xiaoyao-jianfa" )
                return notify_fail("你没有将逍遥剑法运用于招架中，无法施展逍遥连环！\n");

        if( me->query_skill("xiaoyao-jianfa",1) < 150 )
                return notify_fail("你的逍遥剑法修为不足，还不会使用逍遥连环！\n");

        skill =  ( me->query_skill("xiaoyao-jianfa")
                + me->query_skill("force") ) / 5;

        if( me->query("neili") <= skill*3 )
                return notify_fail("你的内力不够使用逍遥连环！\n");
        if( me->query("jingli") <= skill )
                return notify_fail("你的精力不够使用逍遥连环！\n");
        if( me->query("jing") <= skill )
                return notify_fail("你的精不够使用逍遥连环！\n");

        weapon = me->query_temp("weapon");
        
        me->add("neili",-225);
        me->add("jingli",-100);
        
        if(skill>550) skill=550;

	me->set_temp("apply/speed", me->query_temp("apply/speed",1)+skill/3);
        me->set_temp("apply/parry", skill/2);
	me->set_temp("apply/dodge", skill/2);
	me->set_temp("apply/defence", skill/2);
	me->set_temp("apply/attack",  skill/2);

        message_vision(HIY "\n\n$N微微一笑，身随意转，剑走轻盈，「唰！唰！唰」地向$n刺出三剑。\n\n"NOR, me, target);
        
              
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        
        me->add_temp("apply/attack", skill/2);       
        me->add_temp("apply/damage", skill);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->add_temp("apply/attack", -(skill/2));
        me->add_temp("apply/damage", -(skill));
             
        message_vision(HIY "\n\n三剑过后，$N剑尖划了一个圆圈，忽而左手持剑，忽而右手持剑，目光闪闪，寻找着$n的破绽。\n" NOR, me, target);
        
        me->set_temp("xiaoyao",1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/15 );
        return 1;
}

int remove_effect(object me)
{
        me->set_temp("apply/parry", 0);
	me->set_temp("apply/attack", 0);
	me->set_temp("apply/dodge", 0);
	me->set_temp("apply/speed", 0);
	me->set_temp("apply/defence", 0);
	me->delete_temp("xiaoyao");

	if(me->is_fighting()){
        	message_vision(HIY "\n$N一声清哮，袍袖一挥，将手中的招数放慢。\n"NOR, me);
	} else message_vision(HIY "\n$N长长的吸了一口气，将内力收回。\n"NOR, me);
        return 0;
}


