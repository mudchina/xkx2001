//Cracked by Roath
// /kungfu/skill/riyue-shenzhang.c 日月神掌
// by wsky

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N双眉一扬，一招「日月初升」双拳微微一顿，然后飞快的打向$n的$l",
        "dodge": 30,
        "force": 280,
        "skill_name" : "日月初升",
        "damage_type": "瘀伤"
]),
([      "action": "$N身形一晃，抢在$n的身前，双拳一阴一阳雷霆般的击向$n的$l，好一招「日亏月盈」",
        "dodge": 10,
        "force": 200,
        "skill_name" : "日亏月盈",
        "damage_type": "瘀伤"
]),
([      "action": "$N右跨一步，一招「日月辉明」，左拳一个需晃，右拳闪电般的击向$n的$l",
        "dodge": -20,
        "force": 450,
        "damage": 65,
        "skill_name" : "日月辉明",
        "damage_type": "瘀伤"
]),
([      "action": "$N闪开$n的攻击，右拳猛的打向$n的$l，正是一招「骄日炎炎」",
        "dodge": 10,
        "force": 350,
        "damage": 60,
        "skill_name" : "骄日炎炎",
        "damage_type": "瘀伤"
]),
([      "action": "$N一声狂呼，身上衣衫微微飘起，一招「圣火光明」，双拳一前一后的打向$n的$l",
        "dodge": 10,
        "force": 350,
        "damage": 80,
        "skill_name" : "圣火光明",
        "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="shenghuo-quan"; }
int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练日月拳必须空手。\n");
        if ((int)me->query_skill("shenghuo-xuanming", 1) < 10)
                return notify_fail("你的化功大法火候不够，无法练抽髓掌。\n");

        if ((int)me->query("max_neili") < 60)
                return notify_fail("你的内力太弱，无法练日月拳。");
        return 1;
}


int practice_skill(object me)
{

        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练日月拳。\n");

        if (me->query_skill("riyue-shenzhang", 1) < 50)
                me->receive_damage("jingli", 20);
        else
                me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

mapping query_action(object me, object weapon) 
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
                return __DIR__"riyue-shenzhang/" + action;
}