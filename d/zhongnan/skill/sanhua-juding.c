//Cracked by Roath
//sanhua-juding.c 三花聚顶掌
// sdong 07/98

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「燕抬腮」，右拳斜引，左掌疾出，砰的一响，打向$n腮部",
	"force" : 145,
        "dodge" : 5,
	"parry" : 15,
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "燕抬腮"
]),
([	"action" : "$N左掌虚抬，侧身转向，右掌斜穿而出，使出「猿献果」疾切$n的咽喉",
	"force" : 160,
        "dodge" : 5,
	"parry" : 15,
	"weapon": "右掌",
        "damage_type" : "劈伤",
	"lvl" : 12,
	"skill_name" : "猿献果"
]),
([	"action" : "$N使一式「大关门」，转身抬肘，右掌内穿，夹带风雷之声打向$n的$l",
	"force" : 180,
        "dodge" : 8,
	"parry" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 18,
	"skill_name" : "大关门"
]),
([	"action" : "$N左掌虚拍，$n向右一躲，$N右掌嘭地打出，这一掌正是「虎门手」",
	"force" : 210,
        "dodge" : -5,
	"parry" : 15,
        "damage_type" : "瘀伤",
	"lvl" : 24,
	"skill_name" : "虎门手"
]),
([	"action" : "$N使出「揩磨尘垢」，右手倏地穿出，食中二指张开，手腕向内略转，右肘撞向$n对方鼻梁",
	"force" : 245,
        "dodge" : 10,
	"parry" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 30,
	"skill_name" : "揩磨尘垢"
]),
([	"action" : "$N手肘猛地往$n胸口撞去，乘$n疼痛，已借势跃起，反手一推，使的正是一招「无欠无馀」",
	"force" : 290,
        "dodge" : 15,
	"parry" : 15,
        "damage_type" : "瘀伤",
	"lvl" : 36,
	"skill_name" : "无欠无馀"
]),
([	"action" : "$N右腿向前弓步，一招「红霞贯日」，左手化拳为掌，劲气十足，闪电般地拍向$n的胸口",
	"force" : 535,
    "dodge" : 10,
	"parry" : 15,
    "damage" : 100,
    "damage_type" : "内伤",
	"lvl" : 42,
	"skill_name" : "红霞贯日"
]),
([	"action" : "$N左掌虚晃，右掌往$n左颊斜劈下去，这一招「紫电穿云」却是极精妙的上乘招数，手掌到了中途，去向突换，明明劈向左颊，掌缘却要斩在敌人右颈",
	"force" : 600,
    "dodge" : 10,
	"parry" : 15,
    "damage" : 110,
    "damage_type" : "瘀伤",
	"lvl" : 48,
	"skill_name" : "紫电穿云"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="chunyang-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练三花聚顶掌必须空手。\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 20)
		return notify_fail("你的玄门先天功火候不够，无法学三花聚顶掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练三花聚顶掌。\n");
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
	level = (int)me->query_skill("sanhua-juding", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练三花聚顶掌。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	me->add("neili", -5);
	return 1;
}


string perform_action_file(string action)
{
        return __DIR__"sanhua-juding/" + action;
}
