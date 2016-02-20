//Cracked by Roath
// juehu.c 「虎爪绝户手」
// xQin 5/99
// relate file: /kungfu/condition/juehu_damage.c

#include <ansi.h>
#include <combat.h>
#include "damage_sys.h"

int perform(object me, object target)
{
	mixed foo;
	object weapon;
	string msg, unarmed, type, *limb;
	string attack_skill, dodge_skill, parry_skill;
	int ap, dp, pp, damage, tdamage, enfor, duration;
	int hand, dodge, amount;
	mapping prepare;
	mapping action = ([ "force" : 500, "damage": 1000 ]);

	if( !me->query("wudang/juehu") )
		return notify_fail("你尚未学会「虎爪绝户手」。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施展「虎爪绝户手」！\n");		

	if( !target ) return notify_fail("你要对谁用此狠招？\n");

        if( !living(target) )
                return notify_fail("你现在不必使用「虎爪绝户手」。\n");

	if( target->query_condition("juehu_damage") > 0 )
		return notify_fail("这位" + RANK_D->query_respect(me) +"心肠也太过狠辣，何必赶尽杀绝？\n");
/*
	if( me->query("qi") > me->query("max_qi")/4
		&& !target->query("sell_woman/"+me->query("id")) )
		return notify_fail("恩师教诲：若非遇上生死关头，决计不可轻用此狠招。\n");
*/
	if( !target->is_killing(me->query("id")) || !me->is_killing(target->query("id")) )
		return notify_fail("你并非与"+ target->name() +"生死相搏，何苦用此很招？\n");

	if( (int)me->query("neili") <= 200 )
		return notify_fail("你现在内力太弱，无法施展「虎爪绝户手」。\n");

	if( (int)me->query("jingli") <= 150 )
		return notify_fail("你现在体力太差，无法施展「虎爪绝户手」。\n");

	if( me->query_skill_mapped("force") != "taiji-shengong" 
		&& me->query_skill_mapped("force") != "wudang-jiuyang" )
		return notify_fail("你所用的内功与「虎爪绝户手」气路相悖！\n");

	hand = (int)me->query_skill("hand", 1) / 2;
	dodge = (int)me->query_skill("dodge", 1) / 
		( 2 + target->query_temp("juehu_ob") );
	amount = (int)me->query_skill("force") / 3 +
		(int)me->query_skill("claw", 1) + (int)me->query_skill("finger", 1);

	// basicly wd dizi doesn't have claw and hand skill, 
	// so add this for add some temporary damage and success rate.
	me->add_temp("apply/damage", amount);
	me->add_temp("apply/attack", hand);

	// if victim is the first time meet this perform.
	// success rate will be more highher.
	me->add_temp("apply/dodge", dodge);

	msg = "\n$N当下错步转身，左一回右一旋，绕到了$n身旁。";
	me->add("jingli", -100);

	ap = COMBAT_D->skill_power(me, "hand", SKILL_USAGE_ATTACK);
	ap += COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( target->is_busy() ) dp /= 3;
	if( dp < 1 ) dp = 1;

	if( random(ap) < dp )
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += "\n" + SKILL_D(dodge_skill)->query_dodge_msg();
		me->start_busy(1+random(1));
	}
	else
	{
		weapon = target->query_temp("weapon");
		if( objectp(weapon) )
			switch( weapon->query("skill_type") )
			{
				case "sword" : 	msg += "右手食中两指一张，已夹住$W的剑身！\n"; 
						break;
				case "hook"  :	msg += "右手食中两指一张，已夹住$W！\n"; 
						break;
				case "blade" : 	msg += "右手探出，已抓住了$W的刀背！\n"; 
						break;
				case "whip"  :	msg += "右手探出，已抓住了$W的鞭梢！\n";
						break;
				case "hammer":
				case "pike"  :
				case "staff" :
				case "club"  :
				case "stick" :	msg += "右手探出，已抓住了$W，向後回夺！\n"; 
						break;
				default      :	msg += "\n"; 
						break;
			}
		else msg += "\n";

		msg += HIR"紧跟着左手探出，一招「虎爪绝户手」，猛地里指节成虎爪之形，意传真气，直插$n小腹！\n"NOR;
		me->add("neili", -200);

		ap = COMBAT_D->skill_power(me, "hand", SKILL_USAGE_ATTACK);
		ap += COMBAT_D->skill_power(me, "claw", SKILL_USAGE_ATTACK);
		if( ap < 1 ) ap = 1;

		pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
		if( objectp(weapon) ) pp /= 2;	// because we blocked victim's weapon,
		if( pp < 1 ) pp = 1;		// he can not use both hand to parry.

		if( random(ap + pp) < pp )
		{
			parry_skill = target->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available() ) 
				parry_skill = "parry";
			msg += SKILL_D(parry_skill)->query_parry_msg(me->query_temp("weapon"), target);
			// this is not bug :), I use me->query_temp("weapon"), because I don't 
			// want it appear weapon parry msg, we blocked victim's weapon already.
			me->start_busy(2+random(2));
		}
		else 
		{
			if( objectp(weapon) ) weapon->unequip();
			// because we blocked victim's weapon, so don't let it be a factor
			// when calculating damage.
			foo = damage_sys(me, target, "claw", me->query_temp("weapon"), action);
			if( objectp(weapon) ) weapon->wield();

			msg += (string)foo["result"];
			damage = (int)foo["damage"];

			// give victim those who doesn't have special force/dodge/parry
			// have a chance to attack back.
			if( random(target->query("combat_exp")) > me->query("combat_exp")*2/3 
				&& damage*2 > target->query("qi") )
			{

				msg += "$n无可抵挡，";
				if( objectp(weapon) )
				{
					msg += "右手放脱$W，";
					weapon->unequip();
					weapon->move(environment(target));
				}
				target->reset_action();

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
					case "strike" :	msg += "反掌向$N还劈，";
							unarmed = "手掌";
							type = random(2)?"劈伤":"瘀伤";
							break;
					case "cuff"   :	msg += "挥拳向$N猛击，";
							unarmed = "拳头";
							type = "瘀伤";
							break;
					case "claw"   :	msg += "五指向$N$l插落，";
							unarmed = "手爪";
							type = random(2)?"刺伤":"抓伤";
							break;
					case "finger" :	msg += "手指向$N$l戳去，";
							unarmed = "手指";
							type = "刺伤";
							break;
					case "hand" :	msg += "左手向$N按去，";
							unarmed = "左手";
							type = "内伤";
							break;
					case "kick" :	msg += "飞出一腿踢向$N，";
							unarmed = "飞腿";
							type = "瘀伤";
							break;
					default :	msg += "一张口咬向$N的$l，";
							unarmed = "牙齿";
							type = "咬伤";
							break;
				}
				msg += "只盼和$P斗个同归于尽。\n";
				enfor = (int)target->query("jiali");
				target->set("jiali", (int)target->query("force")/2);

				ap = COMBAT_D->skill_power(target, attack_skill, SKILL_USAGE_ATTACK);
				pp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE);
				if( random(ap + pp) < pp )
				{
					msg += "$N右手拨开$n"+ unarmed +"，左手却仍是运劲疾落。\n";
					damage /= 2;
				}
				else
				{
					if( objectp(weapon) )
						msg = replace_string( msg, "$W", weapon->name() );
       					message_vision(msg, me, target);
					// end the msg here because $P & $p need to be exchange.

					foo = damage_sys(target, me, attack_skill,
						target->query_temp("weapon"), target->query("actions"));
					msg = (string)foo["result"];
					tdamage = (int)foo["damage"];
					if( tdamage < 0 ) tdamage = 0;

					me->receive_damage("qi", tdamage, target);
					if( random(tdamage) > (int)me->query_temp("apply/armor") )
						me->receive_wound("qi", tdamage - 
						(int)me->query_temp("apply/armor"), target);

					limb = me->query("limbs");
					msg += COMBAT_D->damage_msg(tdamage, type);
					msg = replace_string( msg, "$l", limb[random(sizeof(limb))]);
					msg = replace_string( msg, "$w", unarmed );

					message_vision(msg, target, me);
					// start a new msg here again.

					if( tdamage > 0 )
						msg = "( $N"+ COMBAT_D->status_msg((int)me->query("qi")
						*100/(int)me->query("max_qi")) + " )\n";
					else msg = "";
				}
				target->set("jiali", enfor);
			}
			if( damage < 0 ) damage = 0;

			target->receive_damage("qi", damage, me);
			if( random(damage) > (int)target->query_temp("apply/armor") )
				target->receive_wound("qi", damage - 
				(int)target->query_temp("apply/armor"), me);

			msg += COMBAT_D->damage_msg(damage, "刺伤");

			if( damage > 0 )
			{
				msg+= "( $n"+ COMBAT_D->status_msg((int)target->query("qi")
					*100/(int)target->query("max_qi")) + " )\n";

				me->add("shen", -damage*100);
				me->add("wudang/juehu_usage", 1);

				duration = damage/10;
				target->add_temp("apply/attack", -duration);
				target->add_temp("apply/defense", -duration);
				target->set_temp("wudang/juehu_damage", 1);
				target->apply_condition("juehu_damage", duration);
				if( damage > target->query("max_qi")/3
					&& target->query("gender") == "男性" )
				{
					target->set("gender", "无性");
					target->set("ori_gender", "男性");
					tell_object(target, HIB 
					"\n你心中突然掠过一丝不祥的预感．．．\n\n" NOR);
				}
			}
			else
			{
				msg += "$P见$p竟能出奇不意的化解开这一抓，不禁茫然不知所措。\n";
				me->start_busy(3+random(3));
			}

		}
	}
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/attack", -hand);
	me->add_temp("apply/dodge", -dodge);

	msg = replace_string( msg, "$l", "腰部");
	msg = replace_string( msg, "$w", "虎爪五指");
	if( objectp(weapon) ) msg = replace_string( msg, "$W", weapon->name() );
	message_vision(msg, me, target);
	if( wizardp(me) ) tell_object(me, sprintf("damage: %d\n", damage));

	target->add_temp("juehu_ob", 1);
	me->reset_action();
	me->start_busy(1);
	return 1;
}
