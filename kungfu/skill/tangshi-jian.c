//Cracked by Roath
//tangshi-jian.c
//Jay 2/18/97

inherit SKILL;

mapping *action = ({
([	"action" : "$N向前跨上一步，同时口中大喊一声，一式「哥翁喊上来」直刺$n的$l",
	"force" : 10,
	"dodge" : 5,
	"damage" : 10,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([      "action" : "$N向前轻跳，一招「马命风小小」，$w向前轻刺$n的$l",
        "force" : 10,
        "dodge" : 15,
        "damage" : 5,
        "lvl" : 0,
        "damage_type" : "刺伤",
]),
([      "action" : "$N左手放在耳朵后面，仿佛在倾听什么，一招「忽听喷惊风」，右手中的$w向前刺向$n的$l",
        "force" : 10,
        "dodge" : 5,
        "damage" : 5,
        "lvl" : 5,
        "damage_type" : "刺伤",
]),
([      "action" : "$N一式「连山布若逃」，手中$w的剑势像一疋布一样砍向$n的$l",
        "force" : 20,
        "dodge" : 10,
        "damage" : 10,
        "lvl" : 10,
        "damage_type" : "割伤",
]),
([      "action" : "$N$w胸前一横，一招「是横不敢过」，$w横削$n",
        "force" : 20,
        "dodge" : -5,
        "damage" : 25,
        "lvl" : 15,
        "damage_type" : "割伤",
]),
([  	"action" : "$N向后一闪，一招「落泥招大姐」，招手让$n过来，$w随即刺出",
    	"force" : 20,
    	"dodge" : 15,
    	"damage" : 20,
    	"lvl" : 20,
    	"damage_type" : "刺伤",
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("tangshi-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力不够练躺尸剑法。\n");
	me->receive_damage("jingli", 20);
	return 1;
}

