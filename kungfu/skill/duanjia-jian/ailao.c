//Cracked by Roath
// ailao.c 哀牢山剑意

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int i, a, ap, dp, power;

	if (!target) target=offensive_target(me);

	if (!target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("你不在战斗中！\n");

	weapon=me->query_temp("weapon");

	if (!objectp(weapon) || weapon->query("skill_type") != "sword")
		return notify_fail("你手中无剑，如何使得出哀牢山剑意？\n");

	if (me->query_skill("kurong-changong", 1)<70)
		return notify_fail("你的内功火候未到，无法架御哀牢山剑意！\n");
	
	if (me->query_skill("sword", 1) < 100)
		return notify_fail("你剑法修为不够，无法施展哀牢山剑意！\n");
	
	if (me->query_skill("duanjia-jian",1)<60)
		return notify_fail("你段家剑修为不够，无法施展哀牢山剑意！\n");
	
	if( me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("你所用的内功与哀牢山剑意气路相悖！\n");

	if (me->query("neili") <= 500)
		return notify_fail("你的内力不够使用哀牢山剑意！\n");
	
	message_vision(HIR "\n突然间$N剑法突变，剑气纵横，上六剑，下六剑，前六剑，后六剑，\n\n"NOR, me, target);
	message_vision(HIR "\n左六剑，右六剑，施展哀牢山剑意对$n虚虚实实连刺了三十六剑！\n\n" NOR, me, target);

	if (me->query("combat_exp")*100/target->query("combat_exp")<120)
		a=3;
	else
	{
		if (me->query("combat_exp")*100/target->query("combat_exp")<150)
			a=4;
		else
		{
			if (me->query("combat_exp")*100/target->query("combat_exp")<180)
				a=5;
			else a=6;
		}
	}

	for (i=1; i<=a; i++)
		COMBAT_D->do_attack(me, target, weapon);

	ap = me->query_skill("force")+me->query_skill("sword")/3;
	dp = target->query_skill("force")+target->query_skill("dodge")/3;
	power =  me->query_skill("yiyang-zhi",1) + me->query_skill("duanjia-jian",1);

// 增加攻击力 消耗极大之内力
	if(random(2) == 1
		&& random(ap+dp)*100 > dp*50
		&& (int)me->query_skill("yiyang-zhi", 1) > 200 
		&& me->query("neili") >= 2000 
		&& me->query("family/family_name")=="大理段家")
	{
		message_vision(HIY "\n只见$N剑交左手，右手急运内功将一阳指力贯注在"NOR+weapon->query("name")+NOR HIY"，对着$n补了一剑！\n" NOR, me, target);
		me->add_temp("apply/speed", power/3);
		me->add_temp("apply/damage", power/2);
		me->add_temp("apply/attack", power/2);
		target->add_temp("apply/defense", -power/5);
		target->add_temp("apply/dodge", -power/5);
		target->add_temp("apply/parry", -power/5);
		COMBAT_D->do_attack(me, target, weapon);
		target->add_temp("apply/defense", power/5);
		target->add_temp("apply/dodge", power/5);
		target->add_temp("apply/parry", power/5);
		me->add_temp("apply/speed", -power/3);
		me->add_temp("apply/damage", -power/2);
		me->add_temp("apply/attack", -power/2);
		me->add("neili", -500);
	}
	me->start_busy(a-random(4));
	me->add("neili", -200);
	me->add("jingli", -50);
	return 1;
}