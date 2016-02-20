//Cracked by Roath

inherit SKILL;

mapping *action = ({
([      "action" : "$N左足探出，忽地跃起，脚下纵跳如飞，拉开架子，一招「怀中抱月」，左一拳右一拳连绵向$n捶去",
        "force" : 200,
        "dodge" : 10,
        "lvl" : 0,
        "skill_name" : "怀中抱月",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左足一点，身子似箭离弦，一招「让步跨虎」，倏地向後跃出，在空中扭转身子，左脚飞出，径踢$n的$l",
        "force" : 250,
        "dodge" : 20,
        "lvl" : 12,
        "skill_name" : "让步跨虎",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手左推右钩，左手虚劈一掌，一式「脱靴转身」，右手又横扫一拳",
        "force" : 320,
        "dodge" : 5,
        "lvl" : 24,
        "skill_name" : "脱靴转身",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N衣袖轻抖，人向右转，一式「二郎担山」，左手衣袖突然从身後向$n的$l拂去",
	"force" : 400,
        "dodge" : 5,
	"lvl" : 36,
	"skill_name" : "二郎担山",
	"weapon" : "衣袖",
        "damage_type" : "鞭伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	return notify_fail("你无法练燕青拳。\n");
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
	level   = (int) me->query_skill("yanqing-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	return notify_fail("你不能练燕青拳。\n");
}

