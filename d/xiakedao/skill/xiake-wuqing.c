//Cracked by Roath
// xiake-wuqing.c 侠客无情手

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「谁能书阁下」左手往$n脸上拂去，$n刚要躲闪，$N右手由下而上插向$n的$l",
        "dodge": 10,
        "force": 40,
        "damage": 0,
        "lvl" : 0,  
        "damage_type" : "瘀伤"
]),

});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
      	return notify_fail("练侠客无情手必须空手。\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query_skill("xiake-wuqing", 1) >= 50)
		return notify_fail("你的侠客无情手已经无法再用练来提高了。\n");
      if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}
int valid_combine(string combo) 
{ 	if (strsrch(combo, "xiake") >= 0) 
		return 1;
	else
		return 0;
}
