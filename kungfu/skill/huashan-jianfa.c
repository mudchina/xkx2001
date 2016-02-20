//Cracked by Roath
// huashan-jianfa.c 华山剑法 
// qfy July 9, 1996

inherit SKILL;

mapping *action = ({
([	"action":"$N一招「白云出岫」，剑势灵动轻盈，手中$w点向$n的$l",
	"force" : 150,
        "dodge" : 5,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "白云出岫",
	"damage_type":	"刺伤"
]),
([	"action":"$N使出「有凤来仪」，剑势飞舞而出，内藏五个后着，划向$n的$l",
	"force" : 180,
        "dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 9,
	"skill_name" : "有凤来仪",
	"damage_type":	"割伤"
]),
([	"action":"$N吐气开声一招「天绅倒悬」，$w自上而下划出一个大弧，向$n劈砍下去",
	"force" : 220,
        "dodge" : 8,
	"parry" : 8,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "天绅倒悬",
	"damage_type":	"割伤"
]),
([	"action":"$N向前跨上一步，运足内劲，手中$w使出「白虹贯日」，急劲无踌地直刺$n",
	"force" : 250,
        "dodge" : 10,
	"parry" : 10,
	"damage": 35,
	"lvl" : 25,
	"skill_name" : "白虹贯日",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中的$w自左而右地一晃，使出「苍松迎客」带着呼呼风声直削$n的$l",
	"force" : 280,
        "dodge" : 15,
	"parry" : 15,
	"damage": 40,
	"lvl" : 32,
	"skill_name" : "苍松迎客",
	"damage_type":	"割伤"
]),
([	"action":"$N飞身跃起，一式「金雁横空」，卷起漫天剑影，$w向$n电射而去",
	"force" : 310,
        "dodge" : 15,
	"parry" : 15,
	"damage": 45,
	"lvl" : 40,
	"skill_name" : "金雁横空",
	"damage_type":	"刺伤"
]),
([	"action":"$N凝气守中，$w逼出雪亮剑芒，挥出「无边落木」，一剑快似一剑底地攻向$n",
	"force" : 350,
        "dodge" : 10,
	"parry" : 10,
	"damage": 55,
	"lvl" : 48,
	"skill_name" : "无边落木",
	"damage_type":	"刺伤"
]),
([      "action":"$N驱剑中宫直进，剑尖颤动，中途忽然转而向上，「青山隐隐」端的是变幻无方",
	"force" : 390,
        "dodge" : 5,
	"parry" : 5,
        "damage": 65,
        "lvl" : 55,
        "skill_name" : "青山隐隐",
        "damage_type":  "刺伤"
]),
([      "action":"$N侧身斜刺一剑，一招「古柏森森」卷带着森然剑气，将$n包围紧裹",
        "force" : 410,
        "dodge" : 8,
	"parry" : 8,
        "damage": 75,
        "lvl" : 62,
        "skill_name" : "古柏森森",
        "damage_type":  "割伤"
]),
([	"action":"$N双手握起$w，剑芒暴长，一式「无双无对」，驭剑猛烈绝伦地往$n冲刺",
	"force" : 450,
        "dodge" : 10,
	"parry" : 10,
	"damage": 85,
	"lvl" : 70,
	"skill_name" : "无双无对",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zixia-gong", 1) < 25)
		return notify_fail("你的紫霞神功火候太浅。\n");
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
	level   = (int) me->query_skill("huashan-jianfa",1);
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
		return notify_fail("你的精力不够练华山剑法。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huashan-jianfa/" + action;
}

