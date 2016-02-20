//Cracked by Roath
// ding-unarmed.c 一横一勾拳
inherit SKILL;

mapping *action = ({
([	"action" : "$N左手轻轻一抹，向$n的$l拍去",
	"damage" : 80,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N右手一提，插向$n的$l",
	"damage" : 100,
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="unarmed" || usage=="parry"; }

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
		return notify_fail("你的内力不够练一横一勾拳。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

