//Cracked by Roath
// dingjia-qinnashou.c 丁家擒拿手
// xQin 7/00

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出一招「凤尾手」，右手绕个半圈，欺上去抓住了$n的手腕一扭。",
        "force" : 180,
        "dodge" : 6,
        "lvl" : 0,
        "skill_name" : "凤尾手",
        "damage_type" : "扭伤"
]),
([      "action" : "$N随手使出一招「鹤翔手」，左手肘横过，右手便去抓$n的肩头。",
        "force" : 220,
        "dodge" : 10,
        "lvl" : 20,
        "skill_name" : "鹤翔手",
        "damage_type" : "抓伤"
]),
([      "action" : "$N突然一招「龙腾抓」，双手一前一后，直取$n的左肩。",
        "force" : 260,
        "dodge" : 15,
        "lvl" : 35,
        "skill_name" : "龙腾抓",
        "damage_type" : "抓伤"
]),
([      "action" : "$N右手一招「虎爪手」，抓向$n背心后的「灵台穴」。",
        "force" : 300,
        "dodge" : 19,
        "lvl" : 48,
        "skill_name" : "虎爪手",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手使出一招「玉女拈针」，内力直透中指指尖，拿向$n的后腰。",
        "force" : 360,
        "dodge" : 22,
        "lvl" : 56,
        "skill_name" : "玉女拈针",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练丁家擒拿手必须空手。\n");
        if ((int)me->query_skill("taixuan-gong", 1) < 40)
                return notify_fail("你的太玄功火候不够，无法学三阴绝户手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练丁家擒拿手。\n");
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
        level   = (int) me->query_skill("dingjia-qinnashou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练丁家擒拿手。\n");
        me->receive_damage("jingli", 25);
        me->add("shen", -10);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"dingjia-qinnashou/" + action;
}
