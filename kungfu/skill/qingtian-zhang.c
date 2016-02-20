//Cracked by Roath
// qingtian-zhang.c, 擎天杖
// snowbird, July 99
// 1.1.1.1

inherit SKILL;

mapping *action = ({
([      "action": "$N一立一个翻身，一式「乌龙盘树」，杖尾霍地横卷过来，扫击$n的$l",
        "force" : 150,
        "dodge":  -5,
        "damage": 20,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 0,
        "skill_name" : "乌龙盘树",
]),
([      "action": "$N大喝一声，手中$w化成一片银光，一招「夜战八方」，向$n的$l猛扫过去",
        "force" : 200,
        "dodge": -5,
        "damage": 30,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 10,
        "skill_name" : "夜战八方",
]),
([      "action": "$N蓦然一声长啸，一招「流星赶月」， 手中$w幻成三道白光，分袭$n胸腹要穴",
        "force" : 260,
        "dodge": -10,
        "damage": 40,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 20,
        "skill_name" : "流星赶月",
]),
([      "action": "$N身形陡然飞起三丈多，一式「千斤压顶」，手中$w带着呼啸破空声从天而降",
        "force" : 320,
        "dodge": -10,
        "damage": 40,
        "damage_type": "劈伤",
        "lvl" : 30,
        "skill_name" : "千斤压顶",
]),
([      "action": "$N趁着$n脚步未稳，撵杖向前进招，骤然一指，杖尾起处，「毒蛇寻穴」，直取白$n丹田下“血海穴”",
        "force" : 380,
        "dodge": -10,
        "damage": 40,
        "damage_type": "挫伤",
        "lvl" : 40,
        "skill_name" : "毒蛇寻穴",
]),
([      "action": "$N杖头一转，迅即一招「横扫千军」，刚猛迅捷，如雷霆疾发向$n下三路猛扫过去",
        "force" : 410,
        "dodge": -10,
        "damage": 45,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 50,
        "skill_name" : "横扫千军",
]),
([      "action": "陡然间，$N手中杖光华大盛，$w宛似「蛟龙出海」，登时把$n圈在当中",
        "force" : 440,
        "dodge": -10,
        "damage": 70,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 60,
        "skill_name" : "蛟龙出海",
]),
([      "action": "$N手中$w盘旋，左右飞舞宛如银龙入海，十荡十决，一式「横云断峰」向$n的$l横扫过去",
        "force" : 470,
        "dodge": -10,
        "damage": 75,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 70,
        "skill_name" : "横云断峰",
])
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 150)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("force", 1) < 30){
                return notify_fail("你的内功修为火候太浅。\n");
        }
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
        level   = (int) me->query_skill("qingtian-zhang",1);
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
                return notify_fail("你的臂力不够练擎天杖。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练擎天杖。\n");
        me->receive_damage("jingli", 20);
        if(me->query_skill("qingtian-zhang", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("qingtian-zhang", 1) > 150)
        me->receive_damage("jingli", 5);
        return 1;
}
