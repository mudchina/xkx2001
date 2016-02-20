//Cracked by Roath
// wuxing-quan for npc

inherit SKILL;

mapping *action = ({
([	"action" : "$N将身一跃，一式「苍鹰搏兔」，凌空下击，抓向$n的$l",
	"force" : 180,
        "dodge" : 5,
	"lvl" : 0,
	"skill_name" : "苍鹰搏兔",
        "damage_type" : "抓伤"
]),
([	"action" : "$N五指箕张，一招「饿虎擒羊」，恶狠狠的抓向$n的$l",
	"force" : 200,
        "dodge" : 10,
	"lvl" : 8,
	"skill_name" : "饿虎擒羊",
        "damage_type" : "抓伤"
]),
([	"action" : "$N摆一个骑马蹲裆式，使一招「黑虎偷心」，呼的一拳向$n的$l打去",
	"force" : 220,
        "dodge" : 5,
	"lvl" : 15,
	"skill_name" : "黑虎偷心",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双臂内缩，使招「老树盘根」，单脚钩向$n的$l",
	"force" : 160,
        "dodge" : 10,
	"lvl" : 14,
	"skill_name" : "老树盘根",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「雪花盖顶」，双手前探，猛地拍向$n的$l",
	"force" : 200,
        "dodge" : 5,
	"lvl" : 13,
	"skill_name" : "雪花盖顶",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N扯住$n手臂，一着「顺手牵羊」，顺势将$n朝前一带，双拳击向$n的$l",
	"force" : 160,
        "dodge" : 10,
	"lvl" : 12,
	"skill_name" : "顺手牵羊",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N施出「独劈华山」，力贯双臂，呼地一声劈头盖脸的打向$n的$l",
	"force" : 220,
        "dodge" : 5,
	"lvl" : 10,
	"skill_name" : "独劈华山",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N往后一让，一式「童子拜观音」，双掌一合齐齐劈向$n的$l",
	"force" : 180,
        "dodge" : 14,
	"lvl" : 18,
	"skill_name" : "童子拜观音",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N虚晃一招，使一招「叶底偷桃」，出其不意的反手抓向$n的$l",
	"force" : 180,
        "dodge" : 14,
	"lvl" : 18,
	"skill_name" : "叶底偷桃",
        "damage_type" : "抓伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	return notify_fail("你无法练五形拳。\n");
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
	level   = (int) me->query_skill("wuxing-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	return notify_fail("你不能练五形拳。\n");
}

