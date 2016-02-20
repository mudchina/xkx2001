//Cracked by Roath
// baihong-jianfa 白虹剑法
// by wsky

#include <ansi.h>
#include <combat.h>

inherit SKILL;
#include "/kungfu/skill/force_list.h"

mapping *action = ({
([      "action":"$N左手握拳，右手剑走轻灵，一招巧「白虹一现」，$w化成一道光芒，射向$n的$l",
        "force" : 150,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "白虹一现",
        "damage_type":  "刺伤"
]),
([      "action":"$N使出一招「鹰起云扬」，身形向上飘起，手中$w猛的劈向$n的$l",
        "force" : 180,
        "dodge" : 5,
        "parry" : 5,
        "damage": 30,
        "lvl" : 20,
        "skill_name" : "鹰起云扬",
        "damage_type":  "刺伤"
]),
([      "action":"$N身形一晃，猛然一式「波涛汹涌」，将$w舞得有如波涛，挟着一阵劲风向$n扫去",
        "force" : 250,
        "dodge" : 10,
        "parry" : 10,
        "damage": 60,
        "lvl" : 30,
        "skill_name" : "波涛汹涌",
        "damage_type":  "割伤"
]),
([      "action":"$N一身清嘯，身行一顿，随即将手中$w舞成一道光环，一招「日月无光」卷起地上的灰尘扫$n的$l",
        "force" : 380,
         "dodge" : 15,
        "parry" : 15,
        "damage": 75,
        "lvl" : 60,
        "skill_name" : "日月无光",
        "damage_type":  "割伤"
]),
([      "action":"$N倒转身子，似乎象要逃跑，猛然身行一转，使出一招“回手剑”，剑尖化作几点星光射向$n的$l",
        "force" : 220,
        "dodge" : 8,
        "parry" : 8,
        "damage": 65,
        "lvl" : 65,
        "skill_name" : "回手剑",
        "damage_type":  "刺伤"
]),
([      "action":"$N向左跨出一步，左手捏着剑决，一招「百流汇海」右手$w化出好几道光芒射向$n的$l",
        "force" : 350,
                  "dodge" : 10,
        "parry" : 10,
        "damage": 65,
        "lvl" : 70,
        "skill_name" : "百流汇海",
        "damage_type":  "刺伤"
]),
([      "action":"$N运力纵起丈余，一招「天鹰翱翔」，挥出手中$w，飘然刺向$n的$l",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 35,
        "lvl" : 75,
        "skill_name" : "天鹰翱翔",
        "damage_type":  "刺伤"
]),
([      "action":"$N右手举$w过顶，身子一摆，一招「冰霜雪雨」，$w化做几点寒星射向$n",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 35,
        "lvl" : 80,
        "skill_name" : "冰霜雪雨",
        "damage_type":  "刺伤"
]),
([      "action":"$N将左手握拳，虚击一招，突然面如寒霜，挥出手中$w刺向$n的$l，好一招「风雪江山」",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 35,
        "lvl" : 85,
        "skill_name" : "风雪江山",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w一指，脸上露出微微的笑容，真气飞速地流遍全身，一招「白虹万道」，$w化成万道光芒雷霆般射向$n的$l",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 90,
        "lvl" : 100,
        "skill_name" : "白虹万道",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenghuo-xuanming", 1) < 10)
                return notify_fail("你的圣火玄冥功火候太浅。\n");
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
        	  level   = (int) me->query_skill("baihong-jianfa",1);
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
                return notify_fail("你的精力不够练白虹剑法。\n");
        me->receive_damage("jingli", 25, "精力透支过度死了");
        return 1;
}

string perform_action_file(string action)
{
                  return __DIR__"baihong-jianfa/" + action;
}

