//Cracked by Roath
// shentuo-zhang 神驼雪山掌
// kane 31/8/98

inherit SKILL;
mapping *action = ({
([	"action" : "$N双臂一舒，使出一招「明驼西来」，身形旋转，掌势飘忽，击向$n的$l",
	"force" : 250,
        "dodge" : 0,
        "damage_type" : "内伤",
	"lvl" : 0,
	"skill_name" : "明驼西来"
]),
([	"action" : "$N身形向后一错，左掌阴势，右掌阳型，使出一式「大漠冰扬」，拍向$n的$l",
	"force" : 280,
        "dodge" : 5,
        "damage_type" : "内伤",
	"lvl" : 20,
	"skill_name" : "大漠冰扬"
]),
([	"action" : "$N弹腿飞身，步法阴阳互易，若有若无的踢向$n的$l，正是一招「灵驼骏足」",
	"force" : 300,
        "dodge" : 15,
        "damage_type" : "内伤",
	"lvl" : 30,
	"skill_name" : "灵驼骏足"
]),
([	"action" : "$N身形飞旋，一式「万里飞霜」，掌影纷飞，掌上内劲已把$n的上盘统统罩住",
	"force" : 350,
        "dodge" : 5,
        "damage_type" : "内伤",
	"lvl" : 38,
	"skill_name" : "万里飞霜"
]),
([	"action" : "$N身形急转，半空中一招「神驼冲霄」，头下脚上，刹那间手脚齐攻，击向$n的$l",
	"force" : 350,
        "dodge" : 0,
        "damage_type" : "内伤",
	"lvl" : 46,
	"skill_name" : "神驼冲霄"
]),
([      "action" : "$N掌势一缓，使出一式「雪锁千山」，掌上阴劲如怒涛汹涌，缓缓推向$n的$l",
	"force" : 400,
        "dodge" : 0,
        "damage_type" : "内伤",
        "lvl" : 55,
        "skill_name" : "雪锁千山"
]),
});


int valid_enable(string usage) { return usage=="unarmed" || usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="lingshe-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练神驼雪山掌必须空手。\n");

        if ((int)me->query_skill("hamagong",1) < 15)
                return notify_fail("你的蛤蟆功火候不够，无法学神驼雪山掌。\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练神驼雪山掌。\n");
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
	level = (int)me->query_skill("shentuo-zhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练神驼雪山掌。\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
