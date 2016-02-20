//Cracked by Roath
// chan.c 太极剑法「缠」字诀
// Modified by xQin 6/2000

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, msg1, msg2, msg3, *chan_msg, *chaned_msg, *dodged_msg;
	object weapon, weapon2;
	int foo;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	weapon = me->query_temp("weapon");
	weapon2 = target->query_temp("weapon");

	if( !living(target) )
		return notify_fail("你现在不必使用「缠」字诀。\n");

	if( !weapon || !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，如何使得「缠」字诀？\n");

	if( me->query_temp("yield") )
		return notify_fail("你不出剑，何以使得「缠」字诀？\n");

	if( me->query_temp("chan/"+target->name()) )
		return notify_fail("你已经牵制住"+ target->name() +"了，放胆攻击吧。\n");

	if( (int)me->query_skill("taiji-jian", 1) < 100 )
		return notify_fail("你的太极剑法极不够娴熟，使不出「缠」字诀。\n");

	if( (int)me->query_skill("taiji-shengong", 1) < 80 )
		return notify_fail("你的太极神功修为不够，使不出「缠」字诀。\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你现在的内力不足以运劲成圈！\n");

	if( me->query("jingli") <= 100 )
		return notify_fail("你现在的体力不足以运劲成圈！\n");

	if( me->query_skill_mapped("parry") != "taiji-jian" )
		return notify_fail("你现在无法使用「缠」字诀。\n");

	if( me->query_skill_mapped("force") != "taiji-shengong")
		return notify_fail("你所用的内功与太极剑意气路相悖！\n");

	me->add("neili", -50);
	me->add("jingli", -50);

	if( objectp(weapon2) )
	{
		msg1 = "在$w"CYN"之中";
		msg2 = "$w"CYN;
		msg3 = "手中$w"CYN"倒似不断的在增加重量，五斤、六斤、七斤……十斤、二十斤……\n";
	}
	else
	{
		msg1 = "住$n";
		msg2 = "$n";
		msg3 = "";
	}

	chan_msg = ({
		CYN"\n$N的一柄$W"CYN"在画着一个个圆圈，每一招均是以弧形刺出，以弧形收回。\n"NOR,
		CYN"\n$N心中竟无半点渣滓，以意运剑，$W"CYN"每发一招，便似放出一条细丝，要去缠"+msg1+"。\n"NOR,
		CYN"\n$N持剑画圆，这路太极剑法只是大大小小、正反斜直各种各样的圆圈，要说招数，可说只有一招，然而这一招却永是应付不穷。\n"NOR,
	});

	chaned_msg = ({
		CYN"$W"CYN"发出的细丝越积越多，似是积成了一团团丝绵，将"+msg2+"裹了起来。\n"NOR,
		CYN"$n的招数渐见涩滞，"+msg3+"偶尔一招发出，真力运得不足，便被$W"CYN"带着连转几个圈子。\n"NOR,
		CYN"$n越斗越是害怕，$P便如撒出了一张大网，逐步向中央收紧。\n"NOR,
	});

	dodged_msg = ({
		HIR"可是$n已然看穿了$P的招数，当下孤注一掷，乾坤一击！！\n"NOR,
		HIR"$n微觉招数涩滞，急忙变招，竭尽全身之力中宫疾进，从剑光圈中攻了进去！\n"NOR,
	});

	msg = chan_msg[random(sizeof(chan_msg))];

	foo = me->query_temp("taiji") ? 250 : 200;
	if( random(me->query("combat_exp") * me->query_int() / 100) 
		> (int)target->query("combat_exp") * target->query_int() / foo )
	{
		msg += chaned_msg[random(sizeof(chaned_msg))];
		target->start_busy(2);
		target->set_temp("guarding", 0);

		if( !me->query_temp("guarding") )
                	me->set_temp("guarding", 1);
		me->add_temp("chan/"+target->name(), 1);
		call_out("chan_checking", 1, me, target);

		msg = replace_string(msg, "$W", weapon->name());
		if( objectp(weapon2) )
			msg = replace_string(msg, "$w", weapon2->name());

		message_vision(msg, me, target);
		return 1;
	}
	else
	{
		msg = replace_string(msg, "$W", weapon->name());
		if( objectp(weapon2) )
			msg = replace_string(msg, "$w", weapon2->name());

		message_vision(msg+dodged_msg[random(sizeof(dodged_msg))], me, target);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"));

		message_vision(HIR"\n$P见来势猛恶，回剑挡格。却见$p纵身一跃，已逃出圈外。\n"NOR, me, target);
		me->start_busy(random(3));
		return 1;
	}
}

void chan_checking(object me, object target)
{
	object weapon = me->query_temp("weapon");

//	if( !me->query_temp("chan/"+target->name()) ) return;

	if( !me ) return;

	if( !me->is_fighting() || !living(me) || me->is_ghost() )
	{
		me->delete_temp("chan");
		return;
	}
	else if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
	{
		me->delete_temp("chan");
		me->start_busy(1);
		message_vision(CYN "\n$N手中无剑，剑意顿失！\n"NOR, me);
		return;
	}
	else if( me->query_skill_mapped("sword") != "taiji-jian"
	|| me->query_skill_mapped("parry") != "taiji-jian" )
	{
		me->delete_temp("chan");
		me->start_busy(1);
		message_vision(CYN "\n$N圈转" + weapon->name()+ CYN
		"，突然变招，使出与太极剑意不同的剑法！\n"NOR, me);
		return;
	}
	else if( me->query("neili") <= 100 )
	{
		me->delete_temp("chan");
		me->start_busy(1);
		message_vision(CYN "\n$N偶尔一剑刺出竟然无法圆转如意，原来是真气不足了！\n"NOR,me);
		return;
	}           

	call_out("chan_checking", 1, me, target);
}       
