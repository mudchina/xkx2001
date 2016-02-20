//Cracked by Roath
// yuenu-jian.c 越女剑法
// 取材：《射雕英雄传》韩小莹 + 《越女剑》阿青
// maco

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N施展小巧腾挪之技，一招「白露横江」，招数轻灵翔动，$w横削$n$l",
        "force" : 100,
        "dodge" : 30,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "白露横江",
        "damage_type": "割伤"
]),
([      "action": "$N忽发一招「电照长空」，便如电光急闪，青光闪闪，$w在$n身边刺来划去，招招不离要害",
        "force" : 120,
        "dodge" : 20,
        "damage": 30,
        "lvl" : 10,
        "skill_name" : "电照长空",
        "damage_type": random(2)?"刺伤":"劈伤"
]),
([      "action" : "$N左足一点，剑走轻灵，一招「凤点头」，身子微侧，$w疾刺$n$l，剑尖光芒闪动，又狠又准，的是精微招数",
        "force" : 150,
        "dodge" : 5,
        "damage" : 20,
        "lvl" : 20,
        "skill_name" : "凤点头",
        "damage_type": "刺伤"
]),
([      "action" : "$N展开轻灵身法，绕着$n滴溜溜地转动，$w递出，一招「枝击白猿」，跃身半空连挽两个平花，倏然回剑下削",
        "force" : 180,
        "dodge" : 10,
        "damage" : 50,
        "lvl" : 30,
        "skill_name" : "枝击白猿",
        "damage_type" : "割伤"
]),
([      "action" : "$N身子拗转，一个「翻身探果」，下盘不动，上盘不避，将腰向左一挪，斗然移开半尺，右手$w直撩向$n",
        "force" : 200,
        "dodge" : 5,
        "damage" : 50,
        "lvl" : 40,
        "skill_name" : "翻身探果",
        "damage_type" : "割伤"
]),
([      "action" : "$N左手捏个剑诀，剑随身走，右足绕前，$w「探海斩蛟」，回锋下插，径攻$n下盘，剑法极为精奇",
        "force" : 300,
        "dodge" : 10,
        "damage" : 70,
        "lvl" : 50,
        "skill_name" : "探海斩蛟",
        "damage_type" : random(2)?"刺伤":"劈伤"
]),
([      "action" : "$N左膝一低，曲肘竖肱，一招「起凤腾蛟」，刷的一声，$w猛撩上来",
        "force" : 350,
        "dodge" : 5,
        "damage" : 80,
        "lvl" : 60,
        "skill_name" : "起凤腾蛟",
        "damage_type" : "割伤"
]),
([      "action" : "$N圈转$w，右足曲为前弓，左手捏着剑诀，右手平膀顺肘，横剑向$n急推，于锋锐之中另蕴复杂变化，正是「十万横磨」之势",
        "force" : 400,
        "dodge" : 0,
        "damage" : 100,
        "lvl" : 70,
        "skill_name" : "十万横磨",
        "damage_type" : "割伤"
]),
});


int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if( (int)me->query("max_neili") < 100 )
                return notify_fail("你的内力不够。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for( i = sizeof(action)-1; i >= 0; i-- )
                if( level >= action[i]["lvl"] )
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("yuenu-jian", 1);

        for( i = sizeof(action); i > 0; i-- )
                if( level > action[i-1]["lvl"] )
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query("jingli") < 50 )
                return notify_fail("你的精力不够练越女剑法。\n");

                me->receive_damage("jingli", 20);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yuenu-jian/" + action;
}
