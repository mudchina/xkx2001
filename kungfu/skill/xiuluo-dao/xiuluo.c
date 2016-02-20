//Cracked by Roath
//修罗无常斩
// by xiaojian Jan 15,2001
#include <ansi.h>
#define BASE_WEIGHT 1000		
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon = me->query_temp("weapon");
	int lvl, amount, str,weight,weight1;
	
	if( !target ) target = offensive_target(me);
	else me->set_temp("offensive_target", target);

	if (! wizardp(me)) 
		return notify_fail("目前这功能还不开放！\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("修罗无常斩只能对战斗中的对手使用。\n");

	if( me->query_temp("sl_xiuluo") )
		return notify_fail("你已经施展过修罗无常斩了！\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("你现在正运使着金刚伏魔的内家神通，无法同时施展修罗无常斩！\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 200 )
		return notify_fail("你的混元一气功火候未到，不能施展修罗无常斩！\n");

	if( me->query_skill("buddhism", 1) < 200 )
		return notify_fail("你对禅宗心法不够，无法领会修罗无常斩！\n");

	if( me->query_skill("blade", 1) < 200 )
		return notify_fail("你0的基本刀法尚未纯熟，无法施展修罗无常斩！\n");

	if( me->query_skill("xiuluo-dao", 1) < 200 )
		return notify_fail("你的修罗刀法修为不足，无法施展出修罗无常斩！\n");

	if( me->query_skill_mapped("force") != "hunyuan-yiqi")
		return notify_fail("你所运使的内功并非混元一气功，无法施展修罗无常斩！\n");
    if( me->query_str() < 45 )
        return notify_fail("你的臂力不足以使用修罗无常斩！\n");


	if( me->query("neili") <= 500 )
		return notify_fail("你的内力不足以施展修罗无常斩！\n");

	if( me->query("jingli") <= 250 )
		return notify_fail("你的精力不足以施展修罗无常斩！\n");

	if( (me->query_temp("weapon"))->query("skill_type") != "blade" )
		return notify_fail("你手中无刀，怎么施展修罗无常斩？\n");
	weight = weapon->query_weight();
	weight1 = weight/BASE_WEIGHT;
	if (weight1 <= 1)
	weight1 = 1;
	lvl = (int)me->query_skill("blade", 1); 
	str = me->query_str();
	amount = lvl*2/3;
	message_vision(HIR "\n$N大喝一声,长吸一口气，纵身跃起，唰唰两刀幻成一片刀影从半空中直劈下来。\n" NOR,me);
	message_vision(YEL"只听呼的两声，刀锋离地尚有数尺，地下已是尘沙飞扬，败草落叶被刀风激得团团而舞，端的是威力惊人!\n" NOR,me);
	message_vision(HIG"刹那间$n已被裹在一阵刺骨的刀风之中，不由得倒吸了一口冷气。\n" NOR,me,target);

	me->set_temp("sl_xiuluo", 1);
	me->add_temp("apply/attack", (amount + weight1));
	me->add_temp("apply/damage", amount);
	if (wizardp(me))  
       tell_object(me, sprintf("lvl=%d, weight=%d, str=%d, attack=%d,damage = %d\n", lvl, weight1, str, (amount+weight1),(amount+str)));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	//add more damage to 2nd hit
	me->add_temp("apply/damage",str);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add("neili", -350);
	me->add("jingli", -150);
	me->add_temp("apply/attack", -(amount + weight1));
	me->add_temp("apply/damage", -(amount + str));
	me->delete_temp("sl_xiuluo");
	me->start_busy(2+random(1));
		return 1;
}

