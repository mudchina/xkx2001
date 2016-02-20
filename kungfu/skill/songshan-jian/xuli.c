//Cracked by Roath

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object weapon, int damage);

int perform(object me, object target)
{
        object weapon,cloth;
        int damage, skill;

        weapon = me->query_temp("weapon");
	cloth = me->query_temp("armor/cloth");
	
        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("嵩山剑法催动内劲的法门祗能对战斗中的对手使用。\n");

        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何运劲於剑？\n");

        if( me->query_temp("songshan_attack") )
                return notify_fail("你的剑上正在积蓄劲力！\n");
        
        if( me->query_temp("songshan_wait") )
                return notify_fail("你刚才出剑，已大耗真元，现在无法再行蓄劲！\n");

        if( me->query_skill("songshan-jian",1) < 100 )
                return notify_fail("你的嵩山剑法修为不足，催动内劲亦无用处！\n");

        if( me->query_skill("force", 1) < 100 )
                return notify_fail("你的内功修为不足，催动内劲亦无用处！\n");

        if( me->query("max_neili") <= 2000 )
                return notify_fail("你的内力不够深厚！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不足！\n");

        if( me->query("jingli") <= 1000 )
                return notify_fail("你的精力不足！\n");

        skill = me->query_skill("songshan-jian",1);

        damage = me->query_skill("songshan-jian")/4;

	me->add("neili", -100);
	me->add("jingli", -100);

	
	me->add_temp("apply/speed", -damage);

        message_vision(YEL"$N慢慢提起"+weapon->name()+YEL"，剑尖对准了$n胸口。\n"NOR, me,target);
	if (cloth->query("material") == "cloth")
        message_vision(HIY"但见$N右手衣袖鼓了起来，犹似吃饱了风的帆篷一般，左手衣袖平垂，与寻常无异，足见$P全身劲力都集中到右臂之上，内力鼓荡，连衣袖都欲胀裂，直是非同小可。\n"NOR, me,target);

        me->set_temp("songshan_attack", 1); 
        me->add_temp("songshan_xuli", 1); 
	me->start_busy(1);
	call_out("checking", 1, me, target, weapon,skill,damage);
        return 1;
}

void checking(object me, object target, object weapon, int skill, int damage)
{
	object cloth = me->query_temp("armor/cloth");

	int xuli,jiali;
	jiali = me->query("jiali");
	
	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, weapon, damage);
		return ;
	}

	me->add_temp("songshan_xuli", skill/2 + random(skill) + jiali); 
	me->add("neili",-skill/2);
	me->start_busy(2);
	xuli = me->query_temp("songshan_xuli");

                if( wizardp(me) )
                        tell_object(me,"嵩山剑蓄力已有"+xuli+"，需要"+skill*5+"。\n");

	if( !me->is_fighting() )
	{
		message_vision("\n$N缓缓垂下了手臂，将附着於"+weapon->name()+"上的内力散去。\n", me);
		remove_effect(me, weapon, damage);
		return ;
	}

	else if( environment(weapon) != me || weapon != me->query_temp("weapon") )
	{
		remove_effect(me, weapon, damage);
		return ;
        }
	else if( me->query_skill_mapped("sword") != "songshan-jian" )
	{
		remove_effect(me, weapon, damage);
		return ;
	}
	else if(  (int)me->query("neili") < skill ||(int)me->query("jingli") < skill )
	{
	if (cloth->query("material") == "cloth")
        message_vision("$N剑上内力一松，右手衣袖垂了下来。\n", me,target);
		return ;
	}

	else if(xuli > skill*5){
		
	//蓄劲完成，攻击
	me->set_temp("s_hit",1);
	me->add_temp("apply/attack", skill);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -skill);
	me->delete_temp("s_hit");

	me->set_temp("songshan_wait", 1); 
	call_out("checking2", skill/30 , me, weapon,damage);
		
	remove_effect(me, weapon, damage);

	return ;
	}
		else call_out("checking", 1, me, target, weapon, skill, damage);
		return;
}
void checking2(object me, object weapon, int damage)
{
	tell_object(me,"你觉得丹田中的内息渐渐重行凝聚了。\n");
	me->delete_temp("songshan_wait"); 
}

void remove_effect(object me, object weapon, int damage) 
{
        if (!me) return;
        me->add_temp("apply/speed", damage);
	me->delete_temp("songshan_xuli");
	me->delete_temp("songshan_attack");

}
