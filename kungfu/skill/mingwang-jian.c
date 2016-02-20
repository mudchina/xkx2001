//Cracked by Roath
// mingwang-jian.c 不动明王剑法

inherit SKILL;

mapping *action = ({
([	"action":"$N持剑静立在$n的身前五尺处，半晌不动不移，$n正想上前，忽的剑风已经指向$n的$l",
	"force" : 120,
        "dodge" : 10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "不动",
	"damage_type":	"刺伤"
]),
([	"action":"$N「起手出剑」，左手捏了个长伸佛手印，右手剑一去千里直刺$n的$l",
	"force" : 140,
        "dodge" : 15,
	"damage": 20,
	"lvl" : 9,
	"skill_name" : "起手出剑",
	"damage_type":	"刺伤"
]),
([	"action":"$N使出一式「山崩」，脚踏碎步，急速抢上，剑式刚猛，有如山崩地裂般象$n当头劈下",
	"force" : 160,
        "dodge" : 20,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "山崩",
	"damage_type":	"劈伤"
]),
([	"action":"$N身影晃动，跳起「降魔舞」，口中念六字真言，已绕到$n的身后连刺三剑",
	"force" : 180,
        "dodge" : 30,
	"damage": 35,
	"lvl" : 27,
	"skill_name" : "降魔舞",
	"damage_type":	"刺伤"
]),
([	"action":"$N跳起「鹤舞」，神色傲然，信步上前，反手平削$n的$l",
	"force" : 200,
        "dodge" : 25,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "鹤舞",
	"damage_type":	"割伤"
]),
([	"action":"$N蹿起「龙腾」，向前跳上，手中剑势骄娆，有如化龙般将$n的全身罩于剑风之下",
	"force" : 240,
        "dodge" : 30,
	"damage": 45,
	"lvl" : 45,
	"skill_name" : "龙腾",
	"damage_type":	"割伤"
]),
([	"action":"$N使出一招「玄冥出世」，闭目转身，乘$n惊愕之际，赫然轮起长剑，当头砍下",
	"force" : 280,
        "dodge" : 20,
	"damage": 55,
	"lvl" : 54,
	"skill_name" : "玄冥出世",
	"damage_type":	"割伤"
]),
([	"action":"$N舞起「千旋转」，身子象似陀洛般急转，绕在$n身侧两尺处，忽地停住，长剑拦腰平斩",
	"force" : 320,
        "dodge" : 25,
	"damage": 60,
	"lvl" : 63,
	"skill_name" : "千旋转",
	"damage_type":	"割伤"
]),
([	"action":"$N色似通神，一式「花雨漫天」，剑尖颤动，如水银泄地般向$n全身洒下",
        "force" : 360,
        "dodge" : 30,
        "damage": 65,
        "lvl" : 72,
        "skill_name" : "花雨漫天",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }


int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。\n");
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
	level   = (int) me->query_skill("mingwang-jian",1);
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
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练不动明王剑。\n");
	me->receive_damage("jingli", 25);
	return 1;
}

/*string perform_action_file(string action)
{
	return __DIR__"mingwang-jian/" + action;
}
*/
