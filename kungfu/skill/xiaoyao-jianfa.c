//Cracked by Kafei
// xiaoao-jianfa.c 逍遥剑法
//无约无束，自由自在，随心所欲，豪放不羁，心如山水，志比霞烟，日月入怀，逍遥云天。

#include <ansi.h>
#include <combat.h>
inherit SKILL;

string *name1 = ({ "玉堂穴", "大横穴", "幽门穴", "章门穴", "晴明穴", "紫宫穴",                   
		   "风池穴", "太阳穴", "会阴穴", "长强穴", "灵台穴" });

mapping *action = ({
([      "action" : "$N$w随意轻挑，一式「无约无束」，$w毫无章法地抖出几点金星，时隐时现地飘向$n",
	"force" : 170,
	"dodge" : 15,
	"parry" : 15,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "无约无束",
	"damage_type" : "刺伤"
]),
([      "action" : "$N行似流水，动似浮云，衣袖微扬，递出一招「自由自在」，$w锋划向$n的$l",
	"force" : 210,
	"dodge" : 25,
	"parry" : 15,
	"damage": 30,
	"lvl" : 15,
	"skill_name" : "自由自在",
	"damage_type" : "割伤"
]),
([      "action" : "$N手中$w一闪而出，正是一招「随心所欲」，心意所指，剑光即至，几经变换终不离$n的$l",
	"force" : 270,
	"dodge" : 25,
	"parry" : 20,
	"damage": 55,
	"lvl" : 30,
	"skill_name" : "随心所欲",
	"damage_type" : "刺伤"
]),
([      "action" : "一改剑法之飘逸，$N真气布满全身，将$w舞得大开大和，脚踏中宫，一式「豪放不羁」，$w带着风声朝$n的$l劈去。",
	"force" : 340,
	"dodge" : 20,
	"parry" : 20,
	"damage": 60,
	"lvl" : 40,
	"skill_name" : "豪放不羁",
	"damage_type" : "劈伤"
]),
([      "action" : "$N$w轻挥，一招「心如山水」泱出几层剑浪，翻江捣海一般涌向$n",
	"force" : 380,
	"dodge" : 20,
	"parry" : 20,
	"damage": 70,
	"lvl" : 55,
	"skill_name" : "心如山水",
	"damage_type" : "割伤"
]),
([      "action" : "$N一招「志比霞烟」，身行飘忽不定，$w现出一片霞光，裹住$N，身剑合一，飞向$n",
	"force" : 400,
	"dodge" : 30,
	"parry" : 20,
	"damage": 80,
	"lvl" : 65,
	"skill_name" : "志比霞烟",
	"damage_type" : "割伤"
]),
([      "action" : "$N左手剑决朝$n一引，$w化一招「日月入怀」，剑尖划出一大一小两个圆圈，拢向$n周身上下",
	"force" : 430,
	"dodge" : 20,
	"parry" : 30,
	"damage": 85,
	"lvl" : 75,
	"skill_name" : "日月入怀",
	"damage_type" : "割伤"
]),
([      "action" : "$N身行高纵，一招「逍遥云天」从上递出，$w幻为数十点银芒，恍恍惚惚，飘落向$n",
	"force" : 450,
	"dodge" : 30,
	"parry" : 30,
	"damage": 95,
	"lvl" : 85,
	"skill_name" : "逍遥云天",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("shenghuo-xuanming",1) < 20)
		return notify_fail("你的圣火玄冥功火候未到，暂无法修习逍遥剑法。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
/*
mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("xiaoyao-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
*/
mapping query_action(object me, object weapon)
{
	int i, level, jq;
	object target;
	string msg, name;       

	level   = (int) me->query_skill("xiaoyao-jianfa",1);
	target = me->select_opponent();
	weapon = me->query_temp("weapon");
	jq = level / 80;

	name = name1[random(sizeof(name1))];    

	if (me->query_temp("jianqi_1")) {
	return ([
	"action":HIC"$N右手剑锋一转，手中$w不住颤斗，一片剑辉闪烁不定，紧接着一股剑气奔向$n的"+name+"！" NOR,
	"force" : 440+jq*10,
	"dodge" : 0,
	"parry" : 0,
	"damage": 100+jq*3,
	"weapon": HIW"剑气"NOR,
	"damage_type":  "刺伤"
	]);
	}
	if (me->query_temp("jianqi_2")) {
	return ([
	"action":HIG"$N踏前一步，$w上第二股剑气隔空点向$n的"+name+"，认穴竟无厘毫之差！" NOR,
	"force" : 460+jq*10,
	"dodge" : 0,
	"parry" : 0,
	"damage": 120+jq*3,
	"weapon": HIW"剑气"NOR,
	"damage_type":  "刺伤"
	]);
	}
	if (me->query_temp("jianqi_3")) {
	return ([
	"action":HIW"$N真气激荡，手中$w发出第三股剑气，一道光芒电光石火般直奔$n，剑辉扫向$n的"+name+"！" NOR,
	"force" : 490+jq*10,
	"dodge" : 0,
	"parry" : 0,
	"damage": 140+jq*3,
	"weapon": HIW"剑气"NOR,
	"damage_type":  "刺伤"
	]);
	}
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够修练逍遥剑法。\n");
	me->receive_damage("jingli", 30, "精力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xiaoyao-jianfa/" + action;
}
