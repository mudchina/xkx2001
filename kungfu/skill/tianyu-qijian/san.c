// san.c  天女散花

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage, sp, dp, i;
	string result, str, msg;

	damage = (int)me->query_skill("bahuang-gong", 1);
	damage = damage +  (int)me->query_skill("tianyu-qijian", 1);
	damage = damage +  (int)me->query_skill("sword", 1);

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「天女散花」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
		
	if( (int)me->query_skill("tianyu-qijian", 1) < 100 )
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。\n");

        if ( me->query_skill_mapped("sword") != "tianyu-qijian")
                return notify_fail("你没有激发天羽奇剑到剑法上！\n"); 

	if ((int)me->query_skill("xiaowu-xiang", 1)<100
		&& (int)me->query_skill("bahuang-gong", 1)<100
		&& (int)me->query_skill("beiming-shengong", 1)<100)
		return notify_fail("你的逍遥派内功火候不够。\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派内功！\n");	

	if( (int)me->query("neili", 1) < damage + 200 )
		return notify_fail("你现在内力太弱，不能使用「天女散花」。\n");
			
	message_vision(CYN "\n$N凝神息气，手腕疾抖，挽出千万个剑花，铺天盖地飞向$n。\n"NOR, me,target);

	sp = me->query_skill("sword") + me->query_skill("dodge") + me->query_dex();
	dp = target->query_skill("parry") + target->query_skill("dodge") + me->query_dex();
	sp *= me->query("combat_exp")/1000;
	dp *= target->query("combat_exp")/1000;
	if( random(sp) > random(dp) ) 
	{
		target->start_busy( (int)me->query_skill("tianyu-qijian") / 30 + 1);
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		me->add("neili", -damage);
		message_vision(HIR "\n只见$N剑花聚为一线，穿向$n。\n$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n\n" NOR, me,target);

		str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		message_vision("($N"+str+")\n", target);

		me->start_busy(2);
	} else 
	{
		message_vision(CYN "可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR, me,target);
		me->add("neili", -100);
		me->start_busy(4);
	}
	return 1;
}
