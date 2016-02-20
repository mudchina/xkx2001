//Cracked by Roath
// jianzhi.c 剑指相配攻击
// maco 8/25/1999
// 神雕侠侣(20)：玉箫剑法与弹指功夫均以攻敌穴道为主，剑指相配，精微奥妙

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object weapon, int speed, int damage);

int perform(object me, object target)
{
	object weapon;
	int speed, damage, sword,jianyi;

	weapon = me->query_temp("weapon");
	jianyi = me->query("th_jianyi");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("剑指相配攻击只能对战斗中的对手使用。\n");

 //       if (!me->query("th_jianyi"))
 //	       return notify_fail("你没有领悟剑意，对玉箫剑法的奥妙体会有限，自也无法施展剑指相配的攻势。\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，如何谈得上「剑指相配」？\n");

	if( me->query_temp("th_jianmang") )
		return notify_fail("你正凝神使动「剑芒」，不能再分心了！\n");

	if( me->query_temp("th_jianzhi") )
		return notify_fail("你正在运用剑指相配的攻势！\n");
	
	if( me->query_skill("yuxiao-jian",1) < 100 )
		return notify_fail("你的玉箫剑法修为未到，不能剑指相配攻敌！\n");

	if( me->query_skill("tanzhi-shentong",1) < 100 )
		return notify_fail("你的弹指神通修为未到，不能剑指相配攻敌！\n");

	if( me->query_skill("bitao-xuangong", 1) < 100 )
		return notify_fail("你的碧涛玄功修为不足，强使剑指相配，徒然分散功力！\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
		return notify_fail("你所运使的内功无法与剑指相配之心法协调！\n");
	if( me->query_skill_mapped("finger") != "tanzhi-shentong")
		return notify_fail("你所施展的指法并非弹指神通！\n");

	if( me->query_skill_prepared("finger") != "tanzhi-shentong")
		return notify_fail("你还没有准备好施展弹指神通！\n");

	if( me->query("max_neili") <= 1200 )
		return notify_fail("你的内力修为不足，倘若施展剑指相配，反而会有力分则弱的凶险！\n");

	if( me->query("neili") <= 400 )
		return notify_fail("你的内力不足，不足以施展剑指相配！\n");

	if( me->query("jingli") <= 400 )
		return notify_fail("你的精力不足，不足以施展剑指相配！\n");

	damage = me->query_skill("yuxiao-jian") + me->query_skill("tanzhi-shentong",1);
	damage = damage/4;
	sword = (me->query_skill("sword")*jianyi + me->query_skill("finger") )/6;
	speed = (me->query_skill("sword")+me->query_skill("finger") )/200;
	me->add("neili", -250);
	me->add("jingli", -100);

	//命中率增加
	me->add_temp("apply/speed", speed);
	me->add_temp("apply/attack", damage);
	me->add_temp("apply/damage", damage/2);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	if(me->query_temp("apply/damage") <= 0) me->set_temp("apply/damage", 0);

	message_vision(HIG"$N手中"+weapon->name()+HIG"一腾，飞舞来去，潇洒自如，著著都是攻势，一招不待$n化解开去，第二招第三招已连绵而至！\n"NOR, me,target);

	//第二剑稍快
	me->add_temp("apply/attack", damage/3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -damage/3);

	if(me->is_fighting(target) ){
	message_vision(HIG"$N剑势未止，左手指力已蕴劲弹出，点向$n各路穴道，"+HIW"「玉箫剑法」"NOR+HIG"与"+HIW"「弹指神通」"NOR+HIG"互相为用，越发精微奥妙，变化无穷！\n"NOR, me,target);

	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->wield();
	}
	me->set_temp("th_jianzhi", sword); 

	if(me->query_temp("th_jianzhi") > 70)
	me->set_temp("th_jianzhi", 70); 

	call_out("checking", 1, me, weapon,speed,damage);

	return 1;
}

void checking(object me, object weapon,int speed, int damage)
{
	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	if( !me->is_fighting() )
	{
		message_vision("\n$N见战局已毕，便即收起了剑指相配的功法。\n", me);
		remove_effect(me, weapon, speed, damage);
		return ;
	}

	else if( environment(weapon) != me || weapon != me->query_temp("weapon") )
	{
		message_vision("\n$N手中兵器已失，当下收回了剑指相配的攻势。\n"NOR, me);
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_skill_mapped("sword") != "yuxiao-jian"
	 || me->query_skill_mapped("finger") != "tanzhi-shentong"
	 || me->query_skill_prepared("finger") != "tanzhi-shentong" )
	{
		remove_effect(me, weapon, speed, damage);
		message_vision(HIG"\n$N一挥"+weapon->name()+HIG"，骤然变换招数，不再是玉箫剑法与弹指神通的搭配进击！\n"NOR, me);
		return ;
	}
	else if(  (int)me->query("neili") < 500 ||(int)me->query("jingli") < 500 )
	{
		tell_object(me, HIR "\n你惊觉内息渐弱，再如此快攻恐怕後继乏力，当下不动声色，暗暗收了左手「弹指神通」攻势。\n" NOR);
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_temp("th_jianzhi") <= 20 )
	{
		remove_effect(me, weapon, speed, damage);
		message_vision(HIG"\n$N一挥"+weapon->name()+HIG"，左手食中二指捏起剑诀，心无旁骛地使动「玉箫剑法」！\n"NOR, me);
		return; 
	}

		else call_out("checking", 1, me, weapon,speed,damage);
		return;
}

void remove_effect(object me, object weapon, int speed, int damage) 
{
	if (!me) return;
	me->add_temp("apply/speed", -speed);
	me->add_temp("apply/attack", -damage);  
	me->add_temp("apply/damage", -damage/2);

	if(me->query_temp("apply/damage") <= 0) me->set_temp("apply/damage", 0);

	me->delete_temp("th_jianzhi");
}
