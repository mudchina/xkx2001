//Cracked by Roath
// chanrao.c 《九阴真经》鞭法－「缠绕」
// xQin 8/99
/*
周芷若鞭法奇幻，三招间便已将他圈住，
俞莲舟适才竭尽全力，竟然无法从她的鞭圈中脱出，心下好生骇异。
*/

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg, attack_skill, dodge_skill;
	int ap, dp, wp, rate;
	int whip, dodge, busy_time, random_factor;
	object weapon, weapon2;
	mapping prepare;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("只能在战斗中施展「缠绕」。\n");

	if( !living(target) )
		return notify_fail("你现在不必使用「缠绕」。\n");

	if( (weapon = me->query_temp("weapon"))->query("skill_type") != "whip" )
		return notify_fail("你手中并无趁手的兵器，如何施展「缠绕」？\n");

	if( me->query_temp("yield") )
		return notify_fail("你不出招，何以「缠绕」？\n");

	if( me->query_temp("jiuyin_chanrao/"+target->name()) )
		return notify_fail(target->name() +"已经被缠绕在鞭圈中了。\n");

	if( (whip = (int)me->query_skill("whip")) < 300 )
		return notify_fail("你的鞭法不够娴熟，施展不出「缠绕」。\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你现在的内力不足以抖鞭成圈！\n");

	if( me->query("jingli") <= 300 )
		return notify_fail("你现在的体力不足以抖鞭成圈！\n");

	me->add("neili", -150);
	me->add("jingli", -80);

	msg = HIG"\n$N突然间$W"HIG"抖动，绕成一个个大大小小的圈子，眼看要将$n裹在其间。\n"NOR;

	ap = COMBAT_D->skill_power(me, "whip", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;

        if( random(ap + dp) < dp )
        {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "轻功";
		else dodge_skill = to_chinese(dodge_skill);

		if( dp > ap*2 )
			msg += CYN"$p瞧出厉害，当下施展"+ dodge_skill +"向後滑出丈许，脱出$W"CYN"所绕的鞭圈范围。\n"NOR;
		else if( dp < ap*2/3 )
			msg += CYN"$p心下大骇，急忙竭尽全力施展"+ dodge_skill +"，好不容易从$W"CYN"所绕的鞭圈中脱出。\n"NOR;
		else	msg += CYN"$p心下一惊，立时提气纵跃，施展"+ dodge_skill +"自$W"CYN"所绕的鞭圈之中脱困而出。\n"NOR;

		me->start_busy(1+random(3));
	}
	else
	{
		msg += WHT"$p$w"WHT"上劲力被$P这么一带，登时身不由主，连转了几个身";

		if( objectp(weapon2 = target->query_temp("weapon")) )
		{
			ap = (int)me->query("neili") / 10
				+ whip + (int)me->query_skill("force");
			dp = (int)target->query("neili") / 10
				+ (int)target->query_skill("parry")
				+ (int)target->query_skill("force");

			switch( weapon2->query("skill_type") )
			{
				case "bow"    : wp = 1; break;
				case "whip"   : wp = 1; break;
				case "sword"  : wp = 2; break;
				case "hook"   : wp = 2; break;
				case "blade"  : wp = 2; break;
				case "pike"   : wp = 3; break;
				case "stick"  : wp = 3; break;
				case "club"   : wp = 3; break;
				case "staff"  : wp = 4; break;
				case "axe"    : wp = 5; break;
				case "hammer" : wp = 5; break;
				default       : wp = 3; break;
			}
			rate = 11/8;
			if( (ap>=dp) && ((random(ap-dp)+wp)*rate > wp) ) 
			{
				msg += "，$w"WHT"脱手上扬。\n"NOR;
				weapon2->unequip();
				weapon2->move(environment(target));
				target->reset_action();
			}
			else msg += "。\n"NOR;
		}
		else msg += "。\n"NOR;

		target->start_busy(2);
		target->set_temp("guarding", 0);

		if( !me->query_temp("guarding") )
                	me->set_temp("guarding", 1);

		dodge = target->query_skill("dodge");
		busy_time = (int)whip/8 - (int)dodge/10 + 1;
		if( busy_time < (int)whip/60 ) busy_time = (int)whip/60;
		if( busy_time > (int)whip/20 ) busy_time = (int)whip/20;
		if( wizardp(me) ) tell_object(me, sprintf("\nbusy time: %d, ", busy_time));

		random_factor = busy_time/5;
		if( random_factor > 6 ) random_factor = 6;
		if( random_factor < 2 ) random_factor = 2;
		switch( random(2) )
		{
			case 0 : busy_time += random(random_factor); break; 
			case 1 : busy_time -= random(random_factor); break;
		}
		if( wizardp(me) )
			tell_object(me, sprintf("random factor: %d, new busy time: %d", random_factor-1, busy_time));

		me->delete_temp("jiuyin_chanrao");
		me->add_temp("jiuyin_chanrao/"+target->name(), busy_time);

		remove_call_out("jiuyin_chanrao");
		call_out("jiuyin_chanrao", 1, me, target, weapon);
	}
	msg = replace_string(msg, "$W", weapon->name());
	if( objectp(weapon2) )
		msg = replace_string(msg, "$w", weapon2->name());
	else 
	{
		prepare = target->query_skill_prepare();
		if( !prepare ) prepare = ([]);

		switch( sizeof(prepare) )
		{
			case 0: attack_skill = "unarmed"; break;
			case 1: attack_skill = (keys(prepare))[0]; break;
			case 2: attack_skill = (keys(prepare))[random(2)]; break;
		}
		switch( attack_skill )
		{
			case "strike" :	msg = replace_string( msg, "$w", "掌" ); break;
			case "cuff" :	msg = replace_string( msg, "$w", "拳" ); break;
			case "claw" :	msg = replace_string( msg, "$w", "爪" ); break;
			case "finger" :	msg = replace_string( msg, "$w", "指" ); break;
			case "hand" :	msg = replace_string( msg, "$w", "手" ); break;
			case "kick" :	msg = replace_string( msg, "$w", "脚" ); break;
			default :	msg = replace_string( msg, "$w", "拳脚" ); break;
		}
	}
	message_vision(msg, me, target);
	return 1;
}

void jiuyin_chanrao(object me, object target, object weapon)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() || me->query("neili") <= 100 )
	{
		me->delete_temp("jiuyin_chanrao");
		return;
	}
	if( weapon != me->query_temp("weapon") && living(target) )
	{
		me->delete_temp("jiuyin_chanrao");
		message_vision("\n$N手中"+ weapon->name() +"一失，$n顿感压力骤减，终於能自圈中脱出。\n", me, target);
		return;
	}
	if( !me->is_fighting(target) ) 
	{
		me->delete_temp("jiuyin_chanrao");
		message_vision("$N忽地"+ weapon->name() +"一抖，收了回来。\n", me);
		return;
	}
	if( me->query_skill_mapped("whip") != "feiyu-bian" )
	{
		me->delete_temp("jiuyin_chanrao");
		message_vision(HIG"\n$N一抖"+ weapon->name() +HIG"，鞭法忽变！\n"NOR, me);
		return;
	}
	if( !me->query_temp("jiuyin_chanrao") && living(target) )
	{
		message_vision("\n$n竭尽全力，终於从$N的鞭圈中脱出。\n", me, target);
		return;
	}

	call_out("jiuyin_chanrao", 1, me, target, weapon);
}
