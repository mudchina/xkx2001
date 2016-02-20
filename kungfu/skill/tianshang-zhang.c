//Cracked by Roath
// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// by cleansword

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N使出一招「冰河开冻」，手中$w大开大阖扫向$n的$l",
        "force" : 180,
        "dodge":  -5,
        "damage": 30,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 0,
        "skill_name" : "冰河开冻",
]),
([      "action": "$N手中$w飞舞，一招「山洪涌洌」势不可挡地攻向$n的$l",
        "force" : 200,
        "dodge": -5,
        "damage": 40,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 10,
        "skill_name" : "山洪涌洌",
]),
([      "action": "$N手中$w阵阵风响，一招「山风凛冽」向$n的$l攻去",
        "force" : 250,
        "dodge": -5,
        "damage": 45,
        "damage_type": "挫伤",
        "lvl" : 20,
        "skill_name" : "山风凛冽",
]),
([      "action": "$N手中$w斜摆，划出一道道圆弧，一式「冰天雪地」把$n的身影团团罩住",
        "force" : 300,
        "dodge": -5,
        "damage": 55,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "劈伤",
        "lvl" : 30,
        "skill_name" : "冰天雪地",
]),
([      "action": "$N一招「峰回路转」，$w左右迂回向$n的$l点去",
        "force" : 350,
        "dodge": -10,
        "damage": 60,
        "damage_type": "挫伤",
        "lvl" : 50,
        "skill_name" : "峰回路转",
]),
([      "action": "$N手中$w向外一揽，一式「鹰拿群鹭」，$w首尾截住$n退路，一收$w，击往$n的破绽",
        "force" : 400,
        "dodge": -5,
        "damage": 70,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 80,
        "skill_name" : "鹰拿群路",
]),
([      "action": "$N将身一纵，跃在半空，$w高举过顶，大喝一声，使一招「天山雪崩」，手中$w幻出数十条杖影，将$n上盘要害尽数罩住",
        "force" : 450,
        "dodge": -15,
        "damage": 100,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "劈伤",
        "lvl" : 100,
        "skill_name" : "天山雪崩",
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 80)
                return notify_fail("你的内力不够。\n");
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
        level   = (int) me->query_skill("tianshan-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if (me->query_str() < 20)
                return notify_fail("你的臂力不够练天山杖法。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练天山杖法。\n");
        me->receive_damage("jingli", 20);
        if(me->query_skill("tianshan-zhang", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("tianshan-zhang", 1) > 150)
        me->receive_damage("jingli", 5);
        return 1;
}

string perform_action_file(string action)
{
                  return __DIR__"tianshan-zhang/" + action;
}
