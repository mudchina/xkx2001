//Cracked by Roath
// shexing-diaoshou 蛇形刁手
// qfy August 21, 1996
// be converted to lingshe-quan 灵蛇拳法
// kane 31/8/98

inherit SKILL;
mapping *action = ({
([	"action" : "$N左掌护胸，右臂微举作蛇形，续而向外疾伸，一式「灵蛇出洞」攻向$n的$l",
	"force" : 150,
        "dodge" : 10,
	"damage_type" : "内伤",
	"lvl" : 0,
	"skill_name" : "灵蛇出洞"
]),
([	"action" : "$N使出「画蛇添足」，双手向$n抓去，同时又无声无息地一脚踢向$n的$l",
	"force" : 180,
        "dodge" : 10,
        "damage_type" : "内伤",
	"lvl" : 10,
	"skill_name" : "画蛇添足"
]),
([	"action" : "只见$N跌扑于地，突然反蹦起使出一招「杯弓蛇影」，恶狠狠的抓向$n的$l",
	"force" : 220,
        "dodge" : 15,
        "damage_type" : "抓伤",
	"lvl" : 20,
	"skill_name" : "杯弓蛇影"
]),
([	"action" : "$N一式「蛇鹰互搏」，双手带着嘶嘶破空之声，猛烈迅速地尽往$n上身要害攻击",
	"force" : 260,
        "dodge" : 5,
        "damage_type" : "内伤",
	"lvl" : 38,
	"skill_name" : "蛇鹰互搏"
]),
([	"action" : "$N双手徊旋中幻出万道蛇影，一招「万蛇汹涌」，诡异奇玄、铺天盖地推向$n",
	"force" : 290,
        "dodge" : 10,
        "damage_type" : "内伤",
	"lvl" : 46,
	"skill_name" : "万蛇汹涌"
]),
([      "action" : "$N出其不意地使一式「白蛇吐信」，右手食中两指微分，闪电般地往$n的$l猛捅",
	"force" : 320,
        "dodge" : 15,
        "damage_type" : "内伤",
        "lvl" : 55,
        "skill_name" : "白蛇吐信"
]),
([	"action" : "突见$N双臂柔若无骨地伸缩着，使出「蛇磐青竹」缠住$n，右臂却悄悄地从不可思议处抹到$n的$l",
	"force" : 350,
        "dodge" : 5,
        "damage_type" : "内伤",
	"lvl" : 65,
	"skill_name" : "蛇磐青竹"
]),
([      "action" : "$N双臂一绞，出其不意地使一式「巴蛇吞象」，双手匪夷所思的一扭，缠向$n的$l",
        "force" : 390,
        "dodge" : 0,
        "damage_type" : "内伤",
        "lvl" : 75,
        "skill_name" : "巴蛇吞象"
]),
([      "action" : "$N手脚不抬，使出一式「腾蛇起雾」，身形凌空拔起，飞身撞向$n的$l",
        "force" : 420,
        "dodge" : 5,
        "damage_type" : "内伤",
        "lvl" : 85,
        "skill_name" : "腾蛇起雾"
])
});

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="shentuo-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练灵蛇拳法必须空手。\n");

        if ((int)me->query_skill("hamagong",1) < 15)
                return notify_fail("你的蛤蟆功火候不够，无法学灵蛇拳法。\n");

	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练灵蛇拳法。\n");
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
	level = (int)me->query_skill("lingshe-quan", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练灵蛇拳法。\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
