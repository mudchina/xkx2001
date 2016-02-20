//Cracked by Roath
// dafeng-yunfei
// 大风云飞手

inherit SKILL;

mapping *action = ({
([      "action": "只见$N右手一扬，一招风平浪静，按向$n$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
	"damage": 10,
	"skill_name": "风平浪静",
        "damage_type": "瘀伤"
]),
([      "action": "$N双手平铺向前，左右手忽然分别向$n上下两路攻去，正是一招风流云散",
        "dodge": -15,
        "parry": -20,
        "force": 180,
	"damage": 20,
	"skill_name": "风流云散",
        "damage_type": "瘀伤"
]),
([	"action": "$N使出一招风吹雨打，双手变幻莫测，忽前忽后，雨点般攻向$n周身要穴",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage": 30,
	"skill_name": "风吹雨打",
	"damage_type": "瘀伤"
]),
([	"action": "$N身形飘渺，双手翻飞上下，一招风雨飘摇，另$n不知该防何处是好",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage": 40,
	"skill_name": "风雨飘摇",
	"damage_type": "瘀伤"
]),
([	"action": "$N左掌忽立，右手自右向左，两股力道将$n包围其中，好一招风卷残云",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage": 50,
	"skill_name": "风卷残云",
	"damage_type": "瘀伤"
]),
([	"action": "$N一招风花雪月，双手飘渺无方，劲投掌缘，$n登觉全身被$N内劲包围，无所退避",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"skill_name": "风花雪月",
	"damage": 60,
	"damage_type": "瘀伤"
]),
([	"action": "$N双手如闪电般攻向$n$l，另$n立感措手不及，吓出一身冷汗",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage": 70,
	"skill_name": "风驰电掣",
	"damage_type": "瘀伤"
]),
([	"action": "$N身形错动，双手忽上忽下，忽左忽右，一招风云变幻，端的是飘渺无方，将大风云飞手发挥得淋漓尽致，$n登时不知所措",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage": 80,
	"skill_name": "风云变幻",
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="riyue-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大风云飞手必须空手。\n");
	if ((int)me->query_skill("shenhuo-xuanming", 1) < 20)
		return notify_fail("你的圣火玄冥功火候不够，无法练大风云飞手 。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练大风云飞手。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练大风云飞手。\n");
	me->add("jingli", -30);
	me->add("neili", -5);
	return 1;
}

