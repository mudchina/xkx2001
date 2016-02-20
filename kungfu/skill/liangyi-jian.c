//Cracked by Roath
// liangyi-jian.c 昆仑派 正两仪剑法
// by maco

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N翻身剑，剑诀斜引，一招「百丈飞瀑」，锋芒从半空中直泻下来，向$n的$l斩落",
        "force" : 120,
        "dodge" : -10,
        "lvl" : 0,
        "skill_name" : "百丈飞瀑",
        "damage_type" : "割伤"
]),
([      "action" : "$N剑招忽变，歪歪斜斜地使出一式「雨打飞花」，剑路全走斜势，飘逸无伦，偶尔又夹著一招正式，令$n极难捉摸",
        "force" : 140,
        "dodge" : -10,
        "damage" : 5,
        "lvl" : 20,
        "skill_name" : "雨打飞花",
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑刃平刺而出，锋朝左右，一招「大漠平沙」，$w上剑光渺茫莫测，辽阔无边地刺向$n的$l",
        "force" : 160,
        "dodge" : -5,
        "damage" : 15,
        "lvl" : 40,
        "skill_name" : "大漠平沙",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一振$w，一式「金针渡劫」，出招迅捷无伦，$w陡发嗤嗤声响，剑尖离$n$l已不及半尺",
        "force" : 220,
        "dodge" : 5,
        "damage" : 25,
        "lvl" : 60,
        "skill_name" : "金针渡劫",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w急转，使出一招「神驼骏足」，气度沉稳，直削$n$l，剑势如渊停岳峙，看似古拙，实则蕴藏无穷奥妙",
        "force" : 280,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 80,
        "skill_name" : "神驼骏足",
        "damage_type" : "割伤"
]),
([      "action" : "$N横剑当腹，摆一招「雪拥蓝桥」势，陡然带起一团冷森森的剑光，将$n周身环环裹住",
        "force" : 340,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 100,
        "skill_name" : "雪拥蓝桥",
        "damage_type" : "割伤"
]) ,
([      "action" : "$N剑尖斜指向地，使一招「木叶萧萧」，手腕一抖，剑光暴长，但听飒飒声响，转瞬间已连攻$n身上七八处要害",
        "force" : 380,
        "dodge" : 20,
        "damage" : 50,
        "lvl" : 120,
        "skill_name" : "木叶萧萧",
        "damage_type" : "刺伤"
]) ,
([      "action" : "$N斜出一剑，一招「峭壁断云」，剑势出奇险峻，精妙难言，$w迳削$n的$l，於凌厉剑势之中，暗伏极繁复的後著变化",
        "force" : 450,
        "dodge" : 20,
        "damage" : 70,
        "lvl" : 100,
        "skill_name" : "峭壁断云",
        "damage_type" : "割伤"
])
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	return notify_fail("正两仪剑法并未开放给玩家。\n");
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
        level   = (int) me->query_skill("liangyi-jian",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
		  return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	return notify_fail("正两仪剑法并未开放给玩家。\n");
}

string perform_action_file(string action)
{
        return __DIR__"liangyi-jian/" + action;
}


