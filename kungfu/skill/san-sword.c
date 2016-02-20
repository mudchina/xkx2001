//Cracked by Roath
// San-sword, 散剑
// Ryu
inherit SKILL;

mapping *action = ({
([	"action" : "$N一翻腕，剑尖一挑，刺向$n的$l",
	"damage" : 40,
	"force" : 200,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一提腰，一挥$w，斩向$n的$l",
        "damage" : 60,
        "force" : 250,
        "damage_type" : "割伤"
]),
([      "action" : "$N一抬臂，$w一扬，指向$n的$l",
        "damage" : 80,
        "force" : 300,
        "damage_type" : "刺伤"
]),
([	"action" : "$N$w一抡，划一弧，挑向$n的$l",
	"damage" : 100,
	"force" : 350,
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练散剑。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

