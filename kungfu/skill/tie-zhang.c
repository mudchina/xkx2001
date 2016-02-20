//Cracked by Roath
// tie-zhang 铁掌
// maco

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N大喝一声，双掌有如斧钺般一掌掌向$n劈去，招数凌厉，力道更是刚猛绝伦",
        "force" : 180,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 30,
        "damage_type" : "瘀伤",
        "lvl" : 0,
]),
([      "action" : "$N胸口门户大开，双臂长伸在外，陡然间双掌翻起，手掌心隐隐带著一股黑气，劲风直逼$n$l",
        "force" : 240,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 35,
        "damage_type" : "瘀伤",
        "lvl" : 10,
]),
([      "action" : "$N两手向前平举三次，双掌合拍，铮的一响，铮铮然如金铁相击，身形一幌，已纵到$n身前，双掌齐向$n胸口推出",
        "force" : 360,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 40,
        "damage_type" : "瘀伤",
        "lvl" : 20,
]),
([      "action" : "$N双掌连拍，铮铮作响，声音极是刺耳，突然间呼的一声，出掌向$n劈到，来势奇快，$n脚步未移，掌力距身已不及半尺", 
        "force" : 390,
        "dodge" : 30,
        "damage" : 50,
        "parry" : 10,
        "weapon": "掌风",
        "damage_type" : "割伤",
        "lvl" : 30,
]),
([      "action" : "$N运劲于臂，大吼声中铁掌翻飞，左掌拍出，右手成抓，同时袭到，两股巨力排山倒海般向$n压了过来",
        "force" : 410,
        "parry" : 10,
        "dodge" : 10,
        "damage" : 50,
        "damage_type" : "瘀伤",
        "lvl" : 40,
]),
([      "action" : "$N左掌轻飘飘向$n当胸按来，似柔实刚，以身发掌，手掌不动，以身子前纵之劲向$n击来，竟是威猛迅捷 ，兼而有之",
        "force" : 420,
        "dodge" : 10,
        "parry" : 30,
        "damage" : 40,
        "damage_type" : "内伤",
        "lvl" : 50,
]),
([      "action" : "$N绕著$n缓缓走了一圈，倏地一道极其浑厚的掌力拍出，正是至为刚猛的「铁蒲扇手」",
        "force" : 450,
        "dodge" : 25,
        "parry" : 20,
        "damage" : 30,
        "damage_type" : "瘀伤",
        "lvl" : 60,
]),
([      "action" : "$N退了两步，突然身子微侧，使出一招「阴阳归一」，左掌在右掌上一拍，右掌顺势斜飞击向$n$l，势道猛恶无比",
        "force" : 520,
        "dodge" : 10,
        "parry" : 30,
        "damage" : 40,
        "damage_type" : "内伤",
        "lvl" : 75,
]),
});
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") )
                return notify_fail("练铁掌必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练铁掌功夫。\n");
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
        level = (int)me->query_skill("tie-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练铁掌。\n");
        me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
                return __DIR__"tie-zhang/" + action;
}
