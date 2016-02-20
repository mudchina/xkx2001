//Cracked by Roath
// feiyu-bian.c 《九阴真经》鞭法
// xQin 8/99 暂名：飞雨飘萍鞭

#include <ansi.h>
#include <combat.h>

inherit SKILL;
inherit F_SSERVER;

int special(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action" : "蓦地里只见人影闪动，$N飞身而前，一条$w向$n迎面击至，快速无伦的连连进招",
	"damage_type" : "鞭伤"
]),
([	"action" : "$N身法诡异，鞭法奇幻，手中那$w便如灵蛇颤动，竟从半路弯将过来，直奔$n$l",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中的$w犹似一条柔丝，竟如没半分重量，身子忽东忽西，忽进忽退，在$n身周飘荡不定",
	"damage_type" : "鞭伤"
]),
([	"action" : "突然之间，$N身形一闪一晃，疾退数丈，$w从右肩急甩向后，陡地击向$n$l，正如天外游龙，矢矫而至",
	"damage_type" : "鞭伤"
]),
([	"action" : "$N忽地从$n身旁一闪而过，尚未回身，然而背后竟似生了眼睛一般，$w说到便到，直指$n的$l",
	"damage_type" : "刺伤"
]),
([	"action" : "只见$N身影忽高忽低，飘忽灵动、变幻无方，$w回将过来，疾风暴雨般向$n攻击",
	"damage_type" : "鞭伤"
]),
([	"action" : "$N身在半空，如一只青鹤般凌空扑击而下，身法漫妙无比，$w抖出，对准$n天灵盖砸了下去，狠辣迅捷之极",
	"damage_type" : "内伤"
])
});

int valid_enable(string usage)
{
	return usage == "whip" || usage == "parry";
}

int valid_learn(object me)
{
	if( !me->query_temp("emei/top_dizi") )
		return notify_fail("周芷若看起来不大想指点你这项技能。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, force, dodge, neili;
	object target = offensive_target(me);

	i = random(sizeof(action));
	force = me->query_skill("force");
	dodge = me->query_skill("dodge");
	neili = me->query("neili");

	if( me->query_temp("perform/chanrao/"+target->name()) )
	{
		me->add("neili", -15);
		me->add("jingli", -5);
		me->add_temp("perform/chanrao/"+target->name(), -1);

		if( me->query_temp("perform/chanrao/"+target->name()) < 1 )
		{
			me->delete_temp("perform/chanrao");
			target->start_busy(1);
		}
		else target->start_busy(2);
	}

	if( objectp(me->query_temp("secondary_weapon")) )
	{
		force /= 2;
		neili /= 2;
	}

	return ([
		"action": action[i]["action"],
		"force" : (random(force)+force)/2,
		"damage": 150+(random(neili)+neili)/100,
		"dodge" : (random(dodge)+dodge)/10,
		"damage_type": action[i]["damage_type"],
		"post_action": (: special :)
		]);
}

int practice_skill(object me)
{
	object weapon;
	int level = me->query_skill("feiyu-bian", 1);
	mapping learned = me->query_learned();

	if( !objectp(weapon = me->query_temp("weapon")) 
	|| (string)weapon->query("skill_type") != "whip" )
		return notify_fail("你没有趁手的兵器来练习飞雨飘萍鞭。\n");

	if( (level <= 360 && level > 270) || (level > 180 && level/2*2 == level)
	|| (level > 90 && level/5*5 == level) || (level/10*10 == level) )
		if( learned["feiyu-bian"] > (level + 1) * (level + 1) - 200 )
			return notify_fail("你反复练习著飞雨飘萍鞭，却发觉无论如何都领会不到其精义所在。\n");

	if( (int)me->query("jingli") < 40 )
		return notify_fail("你的体力不够用来练习飞雨飘萍鞭。\n");

	me->add("jingli", -30);
	return 1;
}

/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	return HIB"$n见到$N这般身法鞭法，如风吹柳絮，水送浮萍，实非人间气象，霎时间宛如身在梦中，心中一寒！\n"NOR;
}
*/

int special(object me, object victim, object weapon, int damage)
{
	string skill;
	object weapon2;
	int ap, dp;

	if( objectp(weapon2 = victim->query_temp("weapon")) && damage == RESULT_PARRY )
	{
		ap = (int)me->query("neili") / 10 + (int)me->query("jiali")
			+ (int)me->query_skill("whip")
			+ (int)me->query_skill("force");
		dp = (int)victim->query("neili") / 10 + (int)victim->query("jiali")
			+ (int)victim->query_skill("parry")
			+ (int)victim->query_skill("force");
		ap = (ap + random(ap*2)) / 2;

		if( ap > dp * 2 )
		{
			message_vision( weapon->name() +HIW"与"+ weapon2->name() +
				HIW"相交，轻轻擦的一响，$N只觉虎口发热，"+ weapon2->name() +
				HIW"把持不定，脱手飞出！\n"NOR, victim);
			weapon2->unequip();
			weapon2->move(environment(victim));
			victim->reset_action();
		}
		else if( ap > dp )
			message_vision( weapon->name() +"与"+ weapon2->name() +
				"相交，轻轻擦的一响，$N只觉虎口发热，"+ weapon2->name() +
				"险些儿脱手！\n", victim);
	}

	if( !me->is_fighting(victim) ) return;

	if( objectp(weapon2 = me->query_temp("secondary_weapon")) )
	{
		skill = me->query_skill_mapped(weapon2->query("skill_type"));
		if( (skill == "emei-jian" || skill == "yanxing-dao")
			&& me->query_dex() >= 70 && me->query("jingli") > 200 )
		{
			me->set_temp("weapon", weapon2);
			me->set_temp("secondary_weapon", weapon);
			me->reset_action();

			me->set_temp("action_flag", 1);
			COMBAT_D->do_attack(me, victim, weapon2, TYPE_QUICK);
			me->set_temp("action_flag", 0);

			me->set_temp("weapon", weapon);
			me->set_temp("secondary_weapon", weapon2);
			me->reset_action();
			me->add("jingli", -10);
		}
	}
	else if( damage == RESULT_DODGE && me->query_skill_mapped("finger") == "tiangang-zhi"
		&& me->query_skill_prepared("finger") == "tiangang-zhi" )
	{
		ap = COMBAT_D->skill_power(me, "whip", SKILL_USAGE_ATTACK);
		ap += COMBAT_D->skill_power(me, "finger", SKILL_USAGE_ATTACK);
		if( ap < 1 ) ap = 1;

		dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
		if( dp < 1 ) dp = 1;

        	if( random(ap) > dp )
		{
			if( me->query_skill_prepared("strike") == "jinding-zhang" )
			{
				me->set_temp("restore_jdz", 1);
				me->prepare_skill("strike");
			}
			me->set_temp("tgz_attack", 1);
			me->set_temp("weapon_name", weapon->name());
			weapon->unequip();
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
			weapon->wield();
			me->delete_temp("weapon_name");
			me->delete_temp("tgz_attack");
			if( me->query_temp("restore_jdz") )
			{
				me->prepare_skill("strike", "jinding-zhang");
				me->delete_temp("restore_jdz");
			}
		}
	}
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"feiyu-bian/" + action;
}