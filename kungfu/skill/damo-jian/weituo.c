//Cracked by Roath
// weituo.c 韦陀伏魔剑
// by maco
//xiaojian fix weituo bug on Nov.17,2000
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, int dam,int attack);
void checking(object me,int dam,int attack);
void checking2(object me,int dam,int attack,int old_dam,int old_att);

int perform(object me, object target)
{
	object weapon = me->query_temp("weapon");
	int lv, attack, dam,old_att,old_dam;

	old_att = (int)me->query_temp("apply/attack",1);
	old_dam = (int)me->query_temp("apply/damage",1);
	lv = (int)me->query_skill("damo-jian", 1); 
	//attack = lv/2 + random(lv/2);
	attack = lv/4+ random(lv/2);
	//dam = lv*3/4 + random(lv/4);
	dam = lv/2 + random(lv/4);

	if( !target ) target = offensive_target(me);
	else me->set_temp("offensive_target", target);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("韦陀伏魔剑只能对战斗中的对手使用。\n");

	if( me->query_temp("sl_weituo") )
		return notify_fail("你已经施展出韦陀伏魔剑了！\n");

	if( (int)me->query_temp("jingang") )
		return notify_fail("你现在正运使着金刚伏魔的内家神通，无法同时施展韦陀伏魔剑！\n");

	if( me->query_dex() < 30 )
		return notify_fail("你在身法上先天禀赋不足，不能使用韦陀伏魔剑！\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 100 )
		return notify_fail("你的混元一气功火候未到，无法施展韦陀伏魔剑！\n");

	if( me->query_skill("buddhism", 1) < 100 )
		return notify_fail("你对佛法认知有限，尚未领会韦陀伏魔剑的初步精义！\n");

	if( me->query_skill("sword", 1) < 100 )
		return notify_fail("你的基本剑法尚未纯熟，无法驾驭韦陀伏魔剑！\n");

	if( me->query_skill("damo-jian", 1) < 100 )
		return notify_fail("你的达摩剑法修为不足，尚未领悟出韦陀伏魔剑！\n");

	if( me->query_skill("dodge") < 135 )
		return notify_fail("韦陀伏魔剑需要精妙的轻功配合，方能有效施展！\n");

	if( me->query_skill("sword") < 135 )
		return notify_fail("你剑法未到炉火纯青之境，尚未领悟出韦陀伏魔剑！\n");

	if( me->query_skill_mapped("force") != "hunyuan-yiqi")
		return notify_fail("你所运使的内功并非混元一气功，无法施展韦陀伏魔剑！\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你的内力不足以施展韦陀伏魔剑！\n");

	if( me->query("jingli") <= 500 )
		return notify_fail("你的精力不足以施展韦陀伏魔剑！\n");

	if( (me->query_temp("weapon"))->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能施展韦陀伏魔剑？\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢,没办法施展韦陀伏魔剑! \n");

	message_vision(HIY "\n$N展开「韦陀伏魔剑」剑法，半守半攻，"+ weapon->name() +HIY"使将开来，剑光闪闪，出手甚是迅捷。\n" NOR, me);

	me->add("neili", -250);
	me->add("jingli", -100);

	me->set_temp("sl_weituo", 1);
	me->add_temp("apply/attack", attack);
	me->add_temp("apply/damage", dam);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->set_temp("sl_weituo", 2);
	me->start_call_out( (: call_other, __FILE__, "checking2", me,dam,attack,old_dam,old_att :), 12);
	//call_out("checking", 1, me, dam, attack);
	if (wizardp(me))  
        tell_object(me, sprintf("original damage=%d, original attack= %d,damage = %d,attack = %d\n", old_dam,old_att,dam,attack));
    me->start_call_out( (: call_other, __FILE__, "checking", me,dam,attack :), 1);
	return 1;
}

void checking(object me, int dam, int attack)
{
	int wt, limit;
	object weapon, target;

	weapon = me->query_temp("weapon");
	target = me->query_temp("offensive_target");

	wt = me->query_temp("sl_weituo");
	limit = 1 + (int)me->query_skill("damo-jian", 1)/100;
	
	if( !target || !me->is_fighting(target) ) target = offensive_target(me);

	if( wt > limit || wt > 5 ) {
		message_vision(HIY"\n$N剑锋掠下，挽个逆花，已经将一路「韦陀伏魔剑」使完。\n"NOR, me);
		remove_effect(me, dam, attack);
		me->start_busy(1);
		return;
	}

	if( !weapon || weapon->query("skill_type") != "sword" )
	{
		tell_object(me, "\n你手中无剑，无法继续施展「韦陀伏魔剑」！\n" );
		remove_effect(me, dam, attack);
		return;
	}

	if( !living(me) || me->is_ghost()  )
	{
		remove_effect(me, dam, attack);
		return;
	}

	if( !target || environment(me) != environment(target) || !me->is_fighting() )
	{
		tell_object(me, "\n你收回了「韦陀伏魔剑」的攻势。\n" );
		remove_effect(me, dam, attack);
		return;
	}
	
	if( me->query_skill_mapped("sword") != "damo-jian" )
	{
		message_vision(YEL"\n$N剑法一变，已非达摩剑法的路子，亦不复见「韦陀伏魔剑」招数。\n"NOR, me);
		remove_effect(me, dam, attack);
		return;
	}

	//call_out("checking", 1, me, dam, attack);
	me->start_call_out( (: call_other, __FILE__, "checking", me,dam,attack :), 1);
	return;
}

void remove_effect(object me, int dam, int attack) 
{
	if (!me) return;
	me->add_temp("apply/attack", -attack);
	me->add_temp("apply/damage", -dam);
	me->delete_temp("sl_weituo");
	me->start_busy(1);
}

void checking2(object me,int dam,int attack,int old_dam,int old_att)
{
	if (wizardp(me))  
        tell_object(me, sprintf("after fight original damage=%d, original attack= %d,damage = %d,attack = %d\n", old_dam,old_att,dam,attack));
	if (me->query_temp("sl_weituo"))
	{
		tell_object(me, "\n你吸了口气,缓缓收回了「韦陀伏魔剑」的攻势。\n" );
		me->add_temp("apply/attack", -attack);
		me->add_temp("apply/damage", -dam);
		me->delete_temp("sl_weituo");
	}

	if((int)me->query_temp("apply/attack",1) != old_att)
	{
		me->set_temp("apply/attack",old_att);
	}
	if((int)me->query_temp("apply/damage",1) != old_dam)
	{
		me->set_temp("apply/damage",old_dam);
	}
		

}