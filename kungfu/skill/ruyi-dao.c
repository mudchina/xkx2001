// ruyi-dao.c 如意刀

inherit SKILL;

mapping *action = ({
([     "action" : "$N手中$w斜指，一招「双宿双飞」，反转$w，以刀背向$n的$l敲去",
	"force" : 120,
        "dodge" : -10,
	"lvl" : 0,
	"skill_name" : "双宿双飞",
	"damage_type" : "割伤"
]),
([      "action" : "一式「随心所欲」，$N左手持刀著著进攻，蓦地里$w急旋，缓缓逼向$n的$l",
	"force" : 130,
        "dodge" : -10,
	"damage" : 5,
	"lvl" : 8,
        "skill_name" : "随心所欲",
	"damage_type" : "割伤"
]),
([      "action" : "$N接着使出「心有灵犀」，陡然间风声飒然，右手持$w，一刀自後袭到，跟著又是一刀，拦腰斩向$n",
	"force" : 140,
        "dodge" : -5,
	"damage" : 15,
	"lvl" : 16,
	"skill_name" : "心有灵犀",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「意乱情迷」，$w如影随形的再反手一刀，笔直砍向$n的$l",
	"force" : 160,
        "dodge" : 5,
	"damage" : 25,
	"lvl" : 24,
	"skill_name" : "意乱情迷",
	"damage_type" : "割伤"
]),
([      "action" : "$N一式「海枯石烂」，一个旋身，双手紧握$w，由左肩斜劈$n的$l",
	"force" : 180,
        "dodge" : 10,
	"damage" : 30,
	"lvl" : 33,
        "skill_name" : "海枯石烂",
	"damage_type" : "割伤"
]),
([      "action" : "$N挥舞$w，一招「吹笛萧萧」，连砍数刀，每一刀的力道和角度都不同，忽轻忽重，齐齐劈向$n",
	"force" : 210,
        "dodge" : 15,
	"damage" : 35,
	"lvl" : 42,
        "skill_name" : "吹笛萧萧",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「携手天涯」，借跃空之势，又是双手运刀，$w破空而下，挟风声劈向$n的$l，发出尖锐破空的刀啸声",
	"force" : 240,
        "dodge" : 5,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "携手天涯",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「情归何处」，暴喝声中双手不住舞起$w，每刀都高举过头，时而直劈，时而斜削",
	"force" : 280,
        "dodge" : 20,
	"damage" : 60,
	"lvl" : 60,
	"skill_name" : "情归何处",
	"damage_type" : "割伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("xiaowu-xiang", 1)<25
		&& (int)me->query_skill("bahuang-gong", 1)<25
		&& (int)me->query_skill("beiming-shengong", 1)<25)
		return notify_fail("你的逍遥派内功火候不够，无法学习如意刀。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法学习如意刀。\n");
	if ((int)me->query_skill("blade", 1) <20)
		return notify_fail("你的基本刀法火候不够，无法学习如意刀。\n");
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
	level   = (int) me->query_skill("ruyi-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练如意刀。\n");
        me->receive_damage("jingli", 25, "精力透支过度死了。");
	return 1;
}
string perform_action_file(string action)
{
    return __DIR__"ruyi-dao/" + action;
}
