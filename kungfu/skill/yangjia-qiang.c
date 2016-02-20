//Cracked by Roath
// dangyang-qiangfa.c 杨家枪法 (maco)
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N使招「毒龙出洞」，枪上红缨抖动，卷起碗大枪花，往$n$l直搠过去",
        "force" : 140,
        "dodge" : 10,
        "damage": 60,
        "lvl" : 8,
        "skill_name" : "毒龙出洞", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":"$N倒转$w，一招「白虹经天」，斜身移步，枪杆起处，圆圆一团红影，枪尖上一点寒光疾向$n刺来",
        "force" : 170,
        "dodge" : 20,
        "damage": 70,
        "lvl" : 20,
        "skill_name" : "白虹经天", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w一抖，使出一招「朝天一柱香」，$w挺得笔直，迅捷无伦地刺向$n的$l",
        "force" : 220,
        "dodge" : 10,
        "damage": 80,
        "lvl" : 30,
        "skill_name" : "朝天一柱香", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":"$N挺起$w，一招「凤点头」，红缨抖动，枪尖闪闪往$n$l点到",
        "force" : 270,
        "dodge" : 0,
        "damage": 100,
        "lvl" : 40,
        "skill_name" : "凤点头", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":"$N一招「春雷震怒」，刷刷刷连环三枪，急刺而至，朱缨乱摆，$w嗤嗤声响，颤成一个大红圈子，罩住了$n上下各路",
        "force" : 330,
        "dodge" : 30,
        "damage": 140,
        "lvl" : 50,
        "skill_name" : "春雷震怒", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":"$N踏上一步，使出一招「孤雁出群」，$w来势如风，凌厉无匹地向$n的$l刺去",
        "force" : 350,
        "dodge" : 40,
        "damage": 160,
        "lvl" : 8,
        "skill_name" : "孤雁出群", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "刺伤"
]),
([      "action":"$N使开$w，一式「行步蹬虎」，攒、刺、打、挑、拦、搠、架、闭，枪尖银光闪闪，缨带红光点点，路数精妙无穷，向$n连施猛攻",
        "force" : 400,
        "dodge" : 60,
        "damage": 200,
        "lvl" : 8,
        "skill_name" : "行步蹬虎", 
//        "post_action":  (: call_other, "/adm/daemons/weapond.c", "cut_weapon" :),
        "damage_type":  "刺伤"
])
});

int valid_enable(string usage) { return usage == "pike" || usage == "parry"; }
int valid_learn(object me) { return 1; }

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
        level   = (int) me->query_skill("yangjia-qiang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "pike")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练杨家枪。\n");
        me->receive_damage("jingli", 20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"/yangjia-qiang" + action;
} 




