//Cracked by Kafei
// hebi.c 玉女剑之与全真剑和璧
//by sdong 07/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object victim, int amount);
private int remove_effect(object me, int amount);

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object victim;
	object weapon;

	if( !victim ) victim = offensive_target(me);

	if( !victim || !victim->is_character() || !me->is_fighting(victim) )
		return notify_fail("双剑和璧只能对战斗中的对手使用。\n");

	if( !target )
                return notify_fail("你想与谁进行双剑和璧？\n");

	if( victim->query("id") == target->query("id") )
		return notify_fail("不能与敌人进行双剑和璧！\n");

	if( !target->is_fighting(victim) )
		return notify_fail("你想与其双剑和璧的对象并未与你的敌人搏斗！\n");

	if( target->query_skill_mapped("sword") != "quanzhen-jian" )
		return notify_fail("你想与其双剑和璧的对象所使用的并非全真剑法！\n");

	if(!objectp(weapon = target->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("你想与其双剑和璧的对象并没有用剑！\n");
	
	if( (int)me->query_temp("hebi") ) 
	{
		return notify_fail("你正与"+target->name()+"进行双剑和璧。\n");
	}

	if( (int)target->query_temp("hebi") ) 
                return notify_fail("你想与其双剑和璧的对象正与他人和壁战斗中，无暇与你和璧！\n");


	skill1 = me->query_skill("sword");
	skill2 = target->query_skill("sword");
	skill =  ( skill1 + skill2 ) / 4; 

	message_vision(
	HIR "\n$N与$n突然间双剑一交，玉女剑法与全真剑法配合得天衣无缝，攻势及守势骤然大增！\n\n" NOR, me, target);

	me->add_temp("apply/attack", skill/6);
	me->add_temp("apply/damage", skill/6);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->set_temp("hebi", 1);

    me->add_temp("apply/damage", 180);
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
    me->add_temp("apply/damage", -180);
	me->add("neili", -150);


	target->add_temp("apply/attack", skill/6);
	target->add_temp("apply/damage", skill/6);
	target->add_temp("apply/parry",  skill/2);
	target->add_temp("apply/dodge",  skill/2);
	target->set_temp("hebi", 1);
    target->add_temp("apply/damage", 180);
	COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
	COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
	COMBAT_D->do_attack(target, victim, target->query_temp("weapon"));
    target->add_temp("apply/damage", -180);
	target->add("neili", -150);


	me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim, skill/2 :), 1);

	return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
	object weapon;
	if( !me->query_temp("hebi") || !target->query_temp("hebi") ) return;

	if( !living(victim) || !present(victim->query("id"), environment(me)) ||
		victim->query("qi") <= 50 && me->is_fighting(victim) && target->is_fighting(victim) ) 
	{
		remove_effect(me, amount);
        remove_effect(target, amount);
		message_vision(HIY"$N与$n个自收招，相视一笑。\n\n"NOR, me, target);
				return;
	}
	else if( (!present(victim->query("id"), environment(me)) && target->is_fighting(victim)) 
	|| (!present(target->query("id"), environment(me)) && me->is_fighting(victim)) ) {
		remove_effect(me, amount);
        remove_effect(target, amount);
		tell_object(me, HIR"双剑和璧已然瓦解！\n"NOR);
        tell_object(target, HIR"双剑和璧已然瓦解！\n"NOR);
        tell_object(victim, HIY"双剑和璧已然瓦解，压力顿减，你不由然地松了一口气。\n"NOR);
				return;
	}
 	else if( !present(target->query("id"), environment(me)) 
	|| !target->is_fighting() || !me->is_fighting() || !living(target)
	|| !living(me) || target->is_ghost() || me->is_ghost() ) {
		remove_effect(me, amount);
        remove_effect(target, amount);
		tell_object(me, HIR"双剑和璧已然瓦解！\n"NOR);
		tell_object(target, HIR"双剑和璧已然瓦解！\n"NOR);
		tell_object(victim, HIY"双剑和璧已然瓦解，压力顿减，你不由然地松了一口气。\n"NOR);
				return;
	}
	else if( !objectp(weapon = me->query_temp("weapon")) 
	|| (string)weapon->query("skill_type") != "sword" ) {
		remove_effect(me, amount);
                remove_effect(target, amount);
                tell_object(me, HIR"双剑和璧已然瓦解！\n"NOR);
                tell_object(target, HIR"双剑和璧已然瓦解！\n"NOR);
                tell_object(victim, HIY"双剑和璧已然瓦解，压力顿减，你不由然地松了一口气。\n"NOR);
				return;
	}
	else if( !objectp(weapon = target->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword" ) {
                remove_effect(me, amount);
                remove_effect(target, amount);
                tell_object(me, HIR"双剑和璧已然瓦解！\n"NOR);
                tell_object(target, HIR"双剑和璧已然瓦解！\n"NOR);
                tell_object(victim, HIY"双剑和璧已然瓦解，压力顿减，你不由然地松了一口气。\n"NOR);
				return;
        }

	call_out("check_fight", 1, me, target, victim, amount);
}

private int remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount/3);
	me->add_temp("apply/damage", -amount/3);
	me->add_temp("apply/parry", -amount);
	me->add_temp("apply/dodge", -amount);
	me->delete_temp("hebi");

	return 0;
}
