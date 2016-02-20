// SKILL liuyang-zhang.c 天山六阳掌
// Modified by xuanyuan 8/2001

#include <ansi.h>
#include <combat.h>

inherit SKILL;
inherit F_SSERVER;
int baihong(object me, object victim, int damage);

mapping *action = ({

([	"action" : "$N一招「阳春白雪」，真气吞吐挥洒，於化开$n攻势的同时著著进逼",
	"force" : 150,
	"dodge" : 10,
	"damage" : 30,
	"lvl" : 0,
	"skill_name" : "阳春白雪",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招「岳阳三醉」，双掌招数妙著纷呈，如同花间蝴蝶，蹁跹不定，招招攻向$n周身要害",
	"force" : 180,
	"dodge" : 30,
	"damage" : 35,
	"lvl" : 30,
	"skill_name" : "岳阳三醉",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N气随意转，一招「阳关三叠」，劲力纵控得精妙无比，三道刚力齐攻向$n$l",
	"force" : 200,
	"dodge" : 25,
	"damage" : 50,
	"lvl" : 70,
	"skill_name" : "阳关三叠",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N天山六阳掌绵绵使出，一招「小阳春」，左掌暗劲汹涌催动，意欲破开$n防守，右掌随之而出",
	"force" : 230,
	"dodge" : 20,
	"damage" : 10,
	"lvl" : 80,
	"skill_name" : "小阳春",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N掌力平挥，一招「雁过衡阳」，轻灵飘逸，举重若轻地劈向$n$l",
	"force" : 260,
	"dodge" : 25,
	"damage" : 50,
	"lvl" : 90,
        "weapon":"掌力",
	"skill_name" : "雁过衡阳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N纵气长啸，一招「阳道旱风」，阳刚之力沛然不止，掌风过处如发裂帛之声，$n立觉气息一窒",
	"force" : 300,
	"dodge" : 30,
	"damage" : 80,
	"lvl" : 120,
	"skill_name" : "阳道旱风",
	"damage_type" : "内伤"
]),

([	"action" : "$N沉肩斜身，使出一式「阳歌天钧」，右掌疾按向$n背心灵穴，左掌同时挟带浑厚内力拍出",
	"force" : 350,
	"dodge" : 10,
	"parry" : 10,
	"damage" : 100,
	"lvl" : 150,
	"skill_name" : "阳歌天钧",
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="parry"||usage=="strike"; }

int valid_combine(string combo) { return combo=="zhemei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon"))
		return notify_fail("练天山六阳掌必须空手。\n");
	if ((int)me->query_skill("xiaowu-xiang", 1)<50
		&& (int)me->query_skill("bahuang-gong", 1)<50
		&& (int)me->query_skill("beiming-shengong", 1)<50)
		return notify_fail("你的逍遥派内功火候不够，无法学习天山六阳掌。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法学习天山六阳掌。\n");
	if ((int)me->query_skill("strike", 1) <80)
		return notify_fail("你的基本掌法火候不够，无法学习天山六阳掌。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level, busy_time;
	object target = offensive_target(me);
	object victim;
	string *limbs, limb, msg;

	level = (int)me->query_skill("liuyang-zhang", 1);
	victim = me->select_opponent();
	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	busy_time = level/20;

	if( random(me->query_temp("lingjiu/baihong")) > 50 || me->query_temp("baihong_attack") ) 
	{
		switch( me->query_temp("baihong_attack") )
		{
			case 1: msg = "不料$N左掌一带，掌力绕过$N的身子，直拍向$p$l";
				break;
			case 2: msg = WHT"谁知$N一掌未竭第二掌又至，连催两重劲，掌力便如长蛇之游，奇诡不可设想"NOR;
				break;
			default: msg = WHT"突然间$N掌力破空，拍向$n"+limb+"，劲风扑面，锋利如刀，转而斜砍$p$l"NOR;
				break;
		}

		me->add_temp("lingjiu/baihong", -1); 
		me->add("neili", -30);

		if( wizardp(me) )
			tell_object(me, sprintf("\nap: %d", COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK)));

		return ([
			"action": msg,
			"force" : 380+random(120),
			"dodge" : 10,
			"damage": 120+random(80),
			"damage_type":"内伤",
			"post_action": (: baihong :)
			]);
	}

	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if (me->query_temp("weapon"))
		return notify_fail("练天山六阳掌必须空手。\n");
	if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力不够练天山六阳掌。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练天山六阳掌。\n");
        me->receive_damage("jingli", 25, "精力透支过度死了。");
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liuyang-zhang/" + action;
}
int baihong(object me, object victim, int damage)
{
	int level = (int)me->query_skill("liuyang-zhang", 1)/2;

	me->add_temp("baihong_attack", 1);

	if( damage == RESULT_DODGE && me->query_temp("baihong_attack") < 3 ) 
	{
		me->add_temp("apply/attack", level);

		if( me->query_temp("baihong_attack") == 1 )
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		else me->delete_temp("baihong_attack");

		me->add_temp("apply/attack", -level);
		return 1;
	}
	else me->delete_temp("baihong_attack");
	return 1;
}

