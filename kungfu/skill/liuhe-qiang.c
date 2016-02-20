//Cracked by Roath
// liuhe-qiang.c 六合枪
//kane

inherit SKILL;

mapping *action = ({
([	"action" : "$N沉肩拗背，提起$w向前一送，来势如箭，去势如线，正是一招「四夷宾服」，直刺$n的$l",
	"force" : 230,
      "parry" : 10,
	"damage" : 30,
	"lvl" : 0,
	"skill_name" : "四夷宾服",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w向下一压，一招「美人认针」，虚式一带，忽地转刺$n的$l",
	"force" : 130,
      "parry" : 10,
	"damage" : 40,
	"lvl" : 8,
	"skill_name" : "美人认针",
	"damage_type" : "刺伤"
]),
([	"action" : "$N双手下捺，一招「灵猫捕鼠」，将$n的攻势封在外门，顺势一枪反刺$n的$l",
	"force" : 140,
      "parry" : 15,
	"damage" : 45,
	"lvl" : 16,
	"skill_name" : "灵猫捕鼠",
	"damage_type" : "刺伤"
]),
([	"action" : "$N翻腕一振$w，一招「狮子摇头」，挽出斗大一个枪花，虚虚实实刺向$n的$l",
	"force" : 220,
      "parry" : 5,
	"damage" : 65,
	"lvl" : 24,
	"skill_name" : "狮子摇头",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w一沉，一招「毒龙出洞」，$w如同活物一般翻滚扭动，直撅向$n的$l",
	"force" : 280,
      "parry" : 10,
	"damage" : 50,
	"lvl" : 33,
	"skill_name" : "毒龙出洞",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w一抖，使出一招「朝天一柱香」，$w挺得笔直，迅捷无伦地刺向$n的$l",
	"force" : 310,
      "parry" : 15,
	"damage" : 70,
	"lvl" : 42,
	"skill_name" : "朝天一柱香",
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return usage == "halberd" || usage == "pike" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
/*
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候太浅。\n");
*/
	return 1;
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
	level   = (int) me->query_skill("liuhe-qiang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "pike")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练六合枪。\n");
	me->receive_damage("jingli", 25);
	return 1;
}
