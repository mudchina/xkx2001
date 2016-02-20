// duo.c 空手折梅

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      string msg;
      object weapon, weapon2;
      int skill;
	int exp1,exp2,comb1,comb2;
	int skill1,skill2,neili1,neili2,str1,str2;

      me->clean_up_enemy();
      target = me->select_opponent();

      skill = me->query_skill("zhemei-shou",1);

      if( !(me->is_fighting() ))
              return notify_fail("空手折梅只能对战斗中的对手使用。\n");

      if (objectp(weapon2 = me->query_temp("weapon")))
              return notify_fail("你必须空手。\n");

      if (!objectp(weapon = target->query_temp("weapon")))
         return notify_fail("对方没有兵刃，你不用担心。\n");

      if( skill < 100)
              return notify_fail("你的天山折梅手等级不够, 不能使用空手折梅！\n");

	if ((int)me->query_skill("xiaowu-xiang", 1)<100
		&& (int)me->query_skill("bahuang-gong", 1)<100
		&& (int)me->query_skill("beiming-shengong", 1)<100)
		return notify_fail("你的逍遥派内功火候不够。\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派内功！\n");	

	if( me->query("neili") < 300 )
		return notify_fail("你的内力不够，无法使用空手折梅！\n");

	message_vision(CYN"\n$N凝神闭息劈出一掌，发至中路突然反掌为爪，抓向$n手中的"+weapon->query("name")+CYN"。\n\n"NOR,me,target);

	exp1 = me->query("combat_exp");
	exp2 = target->query("combat_exp");
	skill1 = me->query_skill("zhemei-shou");
	skill2 = target->query_skill("parry");
	neili1 = me->query("neili");
	neili2 = target->query("neili");
	str1 = me->query_str();
	str2 = target->query_str();

	if (exp1 < exp2/3)
	{
		message_vision("谁知$n混若不见，后发先至一个进招挡住了$N的攻势。\n",me,target);
		me->start_busy(1+random(3));
		me->add("neili",-50);
		COMBAT_D->do_attack(target,me,me->query_temp("weapon"));
		return 1;
	}

	if (exp1 > random(exp2))
	{
	message_vision(HIR"$n一不留神，手中"+weapon->query("name")+HIR"已被$N反手抓到。\n\n"NOR,me,target);
		comb1 = str1*neili1*skill1;
		comb2 = str2*neili2*skill2;
	
		if (comb1 > comb2 * 3/5 )
		{
			
	message_vision(HIW"$n只觉一股劲力自"+weapon->query("name")+HIW"传了过来，手腕一麻，手中"+weapon->query("name")+HIW"脱手而出！\n"NOR,me,target);
			weapon->move(me);
			me->add("neili",-50);
			return 1;
		}
	message_vision(HIW"$N翻转手抓大喝一声「撤！」，内力自"+weapon->query("name")+HIW"传出，运劲回夺！\n\n"NOR,me,target);
	message_vision(HIG"$N只觉$n手中的"+weapon->query("name")+HIG"如同铸在铁中一般，只好放手，飘身退开。\n"NOR,me,target);
			me->start_busy(1+random(2));
			me->add("neili",-150);
			return 1;

	}
	message_vision("可是$n的看破了$N的企图，立刻采取守势，飘身躲开$N的攻击。\n",me,target);
	me->add("neili",-50);
	me->start_busy(1+random(2));
	return 1;
}