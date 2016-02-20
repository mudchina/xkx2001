//Cracked by Roath
// 落英神剑掌、兰花拂穴手攻击
// maco 8/25/1999初版，11/13/2000开放
// 李莫愁见她指化为掌，掌化为指，「落英神剑掌」与「兰花拂穴手」交互为用，当真是掌来时如落英缤纷，指拂处若春兰葳蕤，不但招招凌厉，而且丰姿端丽。

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object weapon, int speed, int damage);

int perform(object me, object target)
{
	object weapon;
	int speed, damage, hand;

	weapon = me->query_temp("weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("落英神剑掌和兰花拂穴手的搭配攻击只能对战斗中的对手使用。\n");
	if( me->query("gender") != "女性")
		return notify_fail("你不是女儿身，跟这一招的优雅姿态有点格格不入。\n");

	if( objectp(weapon))
		return notify_fail("你必需先放下武器。\n");

	if( me->query_temp("luoying_lanhua") )
		return notify_fail("你已经使出了落英神剑掌和兰花拂穴手的搭配攻击！\n");
	
	if( me->query_skill("lanhua-fuxue",1) < 90 )
		return notify_fail("你的兰花拂穴手修为不足。\n");

	if( me->query_skill("luoying-shenjian",1) < 90 )
		return notify_fail("你的落英神剑掌修为不足。\n");

	if( me->query_skill("bitao-xuangong", 1) < 100 )
		return notify_fail("你的碧涛玄功修为不足，无法同时施展落英神剑掌和兰花拂穴手！\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
		return notify_fail("你必需先运使碧涛玄功！\n");
	if( me->query_skill_mapped("strike") != "luoying-shenjian")
		return notify_fail("你所施展的掌法并非落英神剑掌，如何能与兰花拂穴手搭配？\n");

	if( me->query("max_neili") <= 1000 )
		return notify_fail("你的内力修为不足！\n");

	if( me->query("neili") <= 400 )
		return notify_fail("你的内力不够！\n");

	if( me->query("jingli") <= 400 )
		return notify_fail("你的精力不够！\n");

	damage = (me->query_skill("lanhua-fuxue",1) + me->query_skill("luoying-shenjian",1))/6;
	hand = (me->query_skill("hand",1)+me->query_skill("strike",1) )/6;
	speed = (me->query_skill("hand",1)+me->query_skill("strike",1) )/200;
	me->add("neili", -80);
	me->add("jingli", -80);

	
	//命中率增加
	me->add_temp("apply/speed", speed);
	me->add_temp("apply/attack", damage);
	me->add_temp("apply/damage", damage/2);

	me->set_temp("luoying_lanhua", 1); 	

	message_vision(HIY"\n$N突然变招，使出「落英神剑掌」来，掌影飘忽於四方八面，或五虚一实，或八虚一实，真如桃林中狂风忽起、万花齐落一般，妙在姿态飘逸，宛若翩翩起舞。\n"NOR, me,target);

	if(me->is_fighting(target) ){
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	message_vision(HIC"\n但见$N指化为掌，掌化为指，「落英神剑掌」与「兰花拂穴手」交互为用，当真是掌来时如落英缤纷，指拂处若春兰葳蕤，不但招招凌厉，而且丰姿端丽。\n"NOR, me,target);

	if(me->is_fighting(target) ){
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	me->set_temp("fuxue", 1); 
	me->start_busy(1);

	call_out("checking", 1, me, weapon,speed,damage);

	return 1;
}

void checking(object me, object weapon,int speed, int damage)
{
	if( !living(me) || me->is_ghost() ){
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	if( !me->is_fighting() ){
		remove_effect(me, weapon, speed, damage);
		message_vision("\n眼下双方交手已毕，$N负手微退，飘然收势。\n"NOR, me);

		return ;
	}

	else if(me->query_temp("weapon")){
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_skill_mapped("strike") != "luoying-shenjian"
	 || me->query_skill_mapped("hand") != "lanhua-fuxue"
	 || (me->query_skill_prepared("hand") != "lanhua-fuxue" && me->query_skill_prepared("strike") != "luoying-shenjian") ){
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if(  (int)me->query("neili") < 500 ||(int)me->query("jingli") < 500 )
	{
		tell_object(me, "\n你惊觉内息渐弱，不易维持如此紧密攻势，当下不使落英神剑掌法，单以兰花拂穴手应敌。\n" NOR);
		remove_effect(me, weapon, speed, damage);
		return ;
	}

		else call_out("checking", 1, me, weapon, speed, damage);
		return;
}

void remove_effect(object me, object weapon, int speed, int damage) 
{
	if (!me) return;
	me->add_temp("apply/speed", -speed);
	me->add_temp("apply/attack", -damage);  
	me->add_temp("apply/damage", -damage/2);
	me->delete_temp("luoying_lanhua");
	me->delete_temp("fuxue");
}
