//Cracked by Roath
// bagua-dao.c 八卦刀
  
inherit SKILL;
mapping *action = ({
([      "action" : "$N$w使出八卦刀，砍向$n",
	"force" : 170,
	"dodge" : 15
	"parry" : 15
	"damage": 20
	"lvl" : 0,
	"skill_name" : "八卦刀",
	"damage_type" : "砍伤"
]),
	// more actions
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("shenghuo-xuanming",1) < 20)
		return notify_fail("你的圣火玄冥功火候未到，暂无法修习八卦刀。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])

	return action[i]["skill_name"];
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("bagua-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
	
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够修练八卦刀。\n");
	me->receive_damage("jingli", 30, "精力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"bagua-dao/" + action;
}
