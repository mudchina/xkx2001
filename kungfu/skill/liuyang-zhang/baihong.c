// baihong.c 「白虹掌力」
// Modified by xuanyuan 8/2001

/*
李秋水得虚竹援手，避过了童姥的急攻，内息已然调匀，说道：“梦郎，我
已不碍事，你让开吧。”左掌拍出，右掌一带，左掌之力绕过虚竹身畔，向
童姥攻去。童姥心下暗惊：“这贱人竟然练成了‘白虹掌力’，曲直如意，
当真了得。”当即还掌相迎。
*/

#include <ansi.h>
void remove_effect(object me,int strike);

int perform(object me)
{
	int force, strike;

	if( !me->is_fighting() )
		return notify_fail("「白虹掌力」只能在战斗中使用。\n");

//	if( !me->query("lingjiu/baihong") )
//		return notify_fail("你未得高人指点，不知该如何施展「白虹掌力」。\n");

	if( me->query_temp("yield") )
		return notify_fail("你不出招，如何使出「白虹掌力」？\n");

	if( me->query_temp("lingjiu/baihong") )
		return notify_fail("你已经在使用「白虹掌力」了！\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
		return notify_fail("你所用的内功与「白虹掌力」心法相悖！\n");

	if( (int)me->query_skill("strike", 1) < 120 )
		return notify_fail("你的掌法修为还不够，难以施展「白虹掌力」！\n");

	if( (int)me->query_skill("force", 1) < 120 )
		return notify_fail("你的内功修为火候未足，无法以把内力运用自如！\n");

	if( me->query("max_neili") <= 1500 )
		return notify_fail("你的内力不够浑厚，内力无法运用自如！\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你的内力不够，内力无法运用自如！\n");

	if( me->query("jingli") <= 200 )
		return notify_fail("你的体力有限，难以施展「白虹掌力」！\n");

	me->add("neili", -100);
	me->add("jingli", -150);

	force = me->query_skill("force")/2;
	strike = me->query_skill("strike")/2;

	me->add_temp("apply/attack", strike);
	me->set_temp("lingjiu/baihong", strike);

	message_vision(WHT "\n$N左掌拍出，右掌一带，左掌之力吞吐不定。
这门功夫乃是逍遥派上乘掌法中的"+ HIW +"‘白虹掌力’"+ NOR + WHT +"，此刻$N掌力曲直如意，当真了得！\n"NOR, me);

	call_out("checking", 1, me, strike);
	return 1;
}

void checking(object me, int strike)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, strike);
		return;
	}
	else if( !me->is_fighting() && !me->is_busy() )
	{
		remove_effect(me, strike);
		message_vision(WHT "\n$N左掌一挥，右掌在前胸画了个弧，收起了吞吐不定的掌力。\n"NOR, me);
		me->start_busy(1);
		return;
	}
	else if( (int)me->query("neili") < (int)me->query("max_neili") / 5 ||
		(int)me->query("jingli") < (int)me->query("max_jingli") / 4 )
	{
	        remove_effect(me, strike);
        	tell_object(me, HIR "\n你微觉内息不畅，不得不将内力收回！\n" NOR);
		message("vision", CYN+"\n"+ me->name() +CYN"双掌一滞，掌力已不如之前游走无常，变幻不定！\n"NOR, environment(me), me);
		me->start_busy(2);
		return;
	}
	else if( me->query_skill_mapped("strike") != "liuyang-zhang" && !me->is_busy() )
	{
		remove_effect(me, strike);
		message_vision(CYN "\n$N圈转手掌，突然变招，掌力已不如之前游走无常，变幻不定！\n"NOR, me);
		return; 
	}
	else if( me->query_temp("lingjiu/baihong") <= 50 )
	{
		remove_effect(me, strike);
		message_vision(HIC "\n$N手掌圈转，已堪堪将一路"+ HIW +"「白虹掌力」"+ HIC +"尽数使出！\n"NOR, me);
		return; 
	}

	call_out("checking", 1, me, strike);
} 

void remove_effect(object me, int strike)
{
	me->delete_temp("lingjiu/baihong");
	me->add_temp("apply/attack", -strike);
}
