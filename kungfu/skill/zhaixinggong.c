//Cracked by Roath
// zhaixinggong.c based on xiaoyaoyou.c
// by yucao
// modified by wsky.

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$n一个「天外摘星」，跃起数尺，躲过了$N这一招。\n",
        "dodge"  : 20,
]),
([      "action" : "$n身形向后一纵，使出一招「飘然出尘」，避过了$N的攻击。\n",
        "dodge"  : 40,
]),
([      "action" : "$n使出「天狼涉水」，恰好躲过了$N的攻势。\n",
        "dodge"  : 60,
]),
([      "action" : "$n一招「织女穿梭」，姿态美妙地躲了开去。\n",
        "dodge"  : 80,
]),
([      "action" : "$n身行一晃，一招「雪飘天山」，若无其事地躲开了$N的攻击。\n",
        "dodge"  : 90,
]),
([      "action" : "$n大袖飘飘，若往若还，使出一招「晓园独步」"+NOR"轻巧的躲开$N的攻势。\n",
        "dodge"  : 100,
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level = (int)me->query_skill("tiyunzong");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage) 
{ 
        return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练摘星功。\n");
        if (me->query_skill("zhaixinggong", 1) < 30)
                me->receive_damage("jingli", 10);
        else    me->receive_damage("jingli", 20);
        return 1;
}

