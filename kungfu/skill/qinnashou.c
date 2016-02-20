//Cracked by Roath
//qinnashou.c  擒拿手
// arthurgu 1999/10

#include <ansi.h>
inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

string* buwei = ({
        "右手肘部",
        "手腕",
        "左手关节",
        "颈部",
        "肩部关节",
        "背心要穴",
        "膝关节",
        "命门"
});

mapping *action = ({
([      "action" : "$N施出擒拿绝技，一错身抓向$n的" + buwei[random(8)] + "",
        "force" : 400,
        "parry" : 5,
        "damage": 80,
        "lvl" : 10,
        "damage_type" : "内伤"
]),

});

int valid_enable(string usage) { return  usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练擒拿手手必须空手。\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 20)
           return notify_fail("你的内功火候不够，无法学擒拿手。\n");
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
        object victim;
        string bw;
        
        if( !victim && me->is_fighting() ) victim = offensive_target(me);
        level   = (int) me->query_skill("qinnashou",1);
        
        bw = buwei[random(sizeof(buwei))];
        if ((int) me->query_skill("douzhuan-xingyi",1) > random(50) && level > random(240) && me->query("neili") > 300
        && me->query("combat_exp") > random(victim->query("combat_exp")*2) && random(2)==0) {
                me->add("neili", -50);
                message_vision(HIC"$N用擒拿技斗然间抓住了$n的"+bw+"!\n"NOR,me,victim);
                message_vision(GRN"$N退避不及，被$n擒拿住"+bw+",行动不免迟缓下来。\n"NOR,victim,me);
                victim->start_busy(1 + random(level/50));
        }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力太低了。\n");
        me->receive_damage("jingli", 15);
        me->add("neili", -5);
       
       return 1;
}

