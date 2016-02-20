// luowang.c 天罗地网 「天罗地网」
// by liu 23/07/2001
// Xuanyuan 5/9/2001修改
/*
但见她双臂飞舞，两只手掌宛似化成了千手千掌，任他八十一只麻雀如何飞滚翻
扑，始终飞不出她只掌所围作的圈子。杨过只看得目瞪口呆，又惊又喜，一定神
间，立时想到：“姑姑是在教我一套奇妙掌法。快用心记着。”当下凝神观看她
如何出手挡击，如何回臂反扑。她发掌奇快，但一招一式，清清楚楚，自成段落。
杨过看了半晌，虽然不明掌法中的精微之处，但已不似初见时那么诧异万分。
*/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
	int skill;
	skill = me->query_skill("tianluo-diwang",1);

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「天罗地网」只能在战斗中使用。\n");

	if((int)me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");

	if((int)me->query_skill("yunu-xinjing",1) < 100)
		return notify_fail("你玉女心经的功力不够不能使用天罗地网!\n");

	if((int)me->query_skill("strike") < 120)
		return notify_fail("你的掌法修为不够,目前还不能使用天罗地网绝技!\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你内力现在不够, 不能使用天罗地网! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	if( target->query_temp("luowang") )
		return notify_fail("对手已在你的天罗地网势之中！\n");

	message_vision(HIM "\n但见$N双臂飞舞，出手挡击回臂反扑发掌奇快，但一招一式清清楚楚自成段落，两只手掌宛似化成了千手千掌！\n"NOR, me,target);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 )
	{
	message_vision( CYN "\n$N心下大骇，飞滚翻扑，始终逃不出$n只掌所围作的圈子! \n" NOR,target,me);

		target->start_busy( (int)me->query_skill("tianluo-diwang",1) / (30+random(10)) );
		target->add_temp("apply/parry", -skill/8);
		target->add_temp("apply/dodge", -skill/8);
		target->set_temp("luowang",1);
		me->add("neili", -150);
		call_out("checking", 1, me, target,skill);
		if(userp(target)) call_out("remove_effect", skill/20, me, target, skill); 
			else call_out("remove_effect", skill/30, me, target, skill);
	}
	else
	{
	message_vision( HIY "\n$N气定神弦，看破了$n的诱惑，纵身一跃，跳了开去。\n" NOR,target,me);
		me->start_busy(1+random(3));
		me->add("neili", -100);
		return 1;
	}

	return 1;
}

void checking(object me, object target, int skill)
{
	if ( target->query_temp("luowang_finished"))
		target->delete_temp("luowang_finished");
	else {
	if( !living(me) || me->is_ghost() )
	{
		target->delete_temp("luowang");
		target->add_temp("apply/parry", skill/8);
		target->add_temp("apply/dodge", skill/8);
		remove_call_out("remove_effect");
		message_vision(HIG"慢慢的，$n已不似初见时那么诧异万分。\n\n"NOR,me,target);
		return ;
	}
	if( !me->is_fighting() )
	{
		target->delete_temp("luowang");
		target->add_temp("apply/parry", skill/8);
		target->add_temp("apply/dodge", skill/8);
		remove_call_out("remove_effect");
		message_vision(HIG"慢慢的，$n已不似初见时那么诧异万分。\n\n"NOR,me,target);
		return ;
	}

	if( me->query_skill_mapped("force") != "yunu-xinjing"
	 || me->query_skill_mapped("strike") != "tianluo-diwang"
	 || me->query_skill_prepared("strike") != "tianluo-diwang" )
	{
		message_vision(HIM"\n$N骤然变换招数，不能再继续用天罗地网牵制对手的攻击！\n"NOR, me);
		target->delete_temp("luowang");
		target->add_temp("apply/parry", skill/8);
		target->add_temp("apply/dodge", skill/8);
		remove_call_out("remove_effect");
		message_vision(HIG"慢慢的，$n已不似初见时那么诧异万分。\n\n"NOR,me,target);
		return ;
	}

	else call_out("checking", 1, me, target,skill);
		return;
	}
	return;
}
private int remove_effect(object me, object target, int skill)
{
	target->delete_temp("luowang");
	target->add_temp("apply/parry", skill/8);
	target->add_temp("apply/dodge", skill/8);
	target->set_temp("luowang_finished",1);
	message_vision(HIG"慢慢的，$n已不似初见时那么诧异万分。\n\n"NOR,me,target);
	return 1;
}
