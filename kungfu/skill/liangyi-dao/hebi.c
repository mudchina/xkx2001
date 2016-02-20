//Cracked by Roath
// hebi.c 反两仪刀法之双刀和璧
// by qfy
// fixed hebi with self and remain dodge after hebi problem, sdong, 07/22/98
// if one player quit, the other will be able to keep the effect. This got fixed now, sdong, 2/9/2000

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object victim, int amount);
private int remove_effect(object me, int amount);

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object victim,weapon;

	if( !victim ) victim = offensive_target(me);

	if( !victim || !victim->is_character() || !me->is_fighting(victim) )
		return notify_fail("双刀和璧只能对战斗中的对手使用。\n");

	if( !target )
                return notify_fail("你想与谁进行双刀和璧？\n");

	if( victim->query("id") == target->query("id") )
		return notify_fail("不能与敌人进行双刀和璧！\n");

	if( target->query("id") == me->query("id") )
		return notify_fail("自己和璧自己？可惜你不会左右互搏！\n");

	if( !target->is_fighting(victim) )
		return notify_fail("你想与其双刀和璧的对象并未与你的敌人搏斗！\n");

	if( target->query_skill_mapped("blade") != "liangyi-dao" )
		return notify_fail("你想与其双刀和璧的对象所使用的并非反两仪刀法！\n");

	if( (int)target->query_temp("hebi") ) 
                return notify_fail("你想与其双刀和璧的对象正与他人和壁战斗中，无暇与你和璧！\n");

	if(!objectp(weapon = target->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade" )
		return notify_fail("你想与其双刀和璧的对象并没有用刀！\n");

	if( (int)me->query_temp("hebi") ) 
		return notify_fail("你正与"+target->name()+"进行反两仪刀法双刀和璧。\n");

	skill1 = me->query_skill("blade");
	skill2 = target->query_skill("blade");
	skill =  ( skill1 + skill2 ) / 4; 

	message_vision(
	HIR "$N与$n突然间双刀一交，攻势及守势飓然大盛，配合得天衣无缝！\n" NOR, me, target);

	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/dodge",  skill/2);
	me->set_temp("hebi", 1);
	target->add_temp("apply/attack", skill/2);
	target->add_temp("apply/dodge",  skill/2);
	target->set_temp("hebi_power", skill/2);
	target->set_temp("hebi", 1);
	target->apply_condition("liangyi_check", 1);

	me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim, skill/2 :), 1);

	return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
	object weapon;
	if( !me || !objectp(me) )
	{
                remove_effect(target, amount);
                tell_object(target, HIR"双刀和璧已然瓦解！\n"NOR);
                tell_object(victim, GRN"双刀和璧已然瓦解，压力顿减，你不由然地松
了一口气。\n"NOR);
	    return;
	}
        if( !target || !objectp(target) )
        {
                remove_effect(me, amount);
                tell_object(me, HIR"双刀和璧已然瓦解！\n"NOR);
                tell_object(me, GRN"双刀和璧已然瓦解，压力顿减，你不由然地松
了一口气。\n"NOR);
            return;
        }

	
	if( !me->query_temp("hebi") || !target->query_temp("hebi") ) return;

	if( !living(victim) || !present(victim->query("id"), environment(me)) ||
		victim->query("qi") <= 50 && me->is_fighting(victim) && target->is_fighting(victim) ) 
	{
		remove_effect(me, amount);
        remove_effect(target, amount);
		message_vision(HIG"$N与$n个自收招，相视一笑。\n\n"NOR, me, target);
				return;
	}
	else if( (!present(victim->query("id"), environment(me)) && target->is_fighting(victim)) 
	|| (!present(target->query("id"), environment(me)) && me->is_fighting(victim)) ) {
		remove_effect(me, amount);
                remove_effect(target, amount);
		tell_object(me, HIR"双刀和璧已然瓦解！\n"NOR);
                tell_object(target, HIR"双刀和璧已然瓦解！\n"NOR);
                tell_object(victim, GRN"双刀和璧已然瓦解，压力顿减，你不由然地松了一口气。\n"NOR);
	}
 	else if( !present(target->query("id"), environment(me)) 
	|| !target->is_fighting() || !me->is_fighting() || !living(target)
	|| !living(me) || target->is_ghost() || me->is_ghost() ) {
		remove_effect(me, amount);
                remove_effect(target, amount);
		tell_object(me, HIR"双刀和璧已然瓦解！\n"NOR);
		tell_object(target, HIR"双刀和璧已然瓦解！\n"NOR);
		tell_object(victim, GRN"双刀和璧已然瓦解，压力顿减，你不由然地松了一口气。\n"NOR);
	}
	else if( !objectp(weapon = me->query_temp("weapon")) 
	|| (string)weapon->query("skill_type") != "blade" ) {
		remove_effect(me, amount);
                remove_effect(target, amount);
                tell_object(me, HIR"双刀和璧已然瓦解！\n"NOR);
                tell_object(target, HIR"双刀和璧已然瓦解！\n"NOR);
                tell_object(victim, GRN"双刀和璧已然瓦解，压力顿减，你不由然地松了一口气。\n"NOR);
	}
	else if( !objectp(weapon = target->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade" ) {
                remove_effect(me, amount);
                remove_effect(target, amount);
                tell_object(me, HIR"双刀和璧已然瓦解！\n"NOR);
                tell_object(target, HIR"双刀和璧已然瓦解！\n"NOR);
                tell_object(victim, GRN"双刀和璧已然瓦解，压力顿减，你不由然地松了一口气。\n"NOR);
    }

	call_out("check_fight", 1, me, target, victim, amount);
}

private int remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/dodge", -amount);
	me->delete_temp("hebi");
	me->delete_temp("hebi_power");

	return 0;
}
