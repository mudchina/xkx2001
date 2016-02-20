//Cracked by Roath
// Luan-blade.c 乱刀
// Ryu
inherit SKILL;

mapping *action = ({
([	"action" : "$N手中$w左一挥右一拦，对准$n的$l就是一戳",
	"damage" : 40,
	"force" : 200,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w上一挑下一撩，向$n的$l捅去",
        "damage" : 60,
        "force" : 250,
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w东一劈西一插，刀锋指向$n的$l",
        "damage" : 80,
        "force" : 300,
        "damage_type" : "刺伤"
]),
([	"action" : "$N手中$w前一指后一扫，刀尖挑向$n的$l",
	"damage" : 100,
	"force" : 350,
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }

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
		return notify_fail("你的内力不够练乱刀。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

