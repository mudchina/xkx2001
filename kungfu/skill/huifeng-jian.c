//Cracked by Roath
// huifeng-jian.c 回风拂柳剑

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「清风袭月」，剑锋平指，剑势如风，一气呵成猛攻$n的$l",
	"force" : 120,
	"dodge" : 30,
	"damage" : 20,
	"lvl" : 0,
	"skill_name" : "清风袭月",
	"damage_type" : "刺伤"
]),
([	"action" : "$N向前跃上一步，左手剑诀，右手$w使出一式「飘雪穿云」直刺$n的$l",
	"force" : 140,
	"dodge" : 20,
	"damage" : 30,
	"lvl" : 10,
	"skill_name" : "飘雪穿云",
	"damage_type" : "刺伤"
]),
([	"action" : "$N$w斜指苍天，一式「千峰竞秀」，化出无数个剑尖，裹向$n的$l",
	"force" : 170,
	"dodge" : 5,
	"damage" : 40,
	"lvl" : 20,
	"skill_name" : "千峰竞秀",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「万流归宗」，$w自上而下缓缓划出一个大弧，突然从中向$n刺出",
	"force" : 200,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 30,
	"skill_name" : "万流归宗",
	"damage_type" : "刺伤"
]),
([	"action" : "$N回身拧腰，一式「乌龙搅柱」，$w随身平划，点向$n的胸腹要穴",
	"force" : 250,
	"dodge" : 5,
	"damage" : 60,
	"lvl" : 40,
	"skill_name" : "乌龙搅柱",
	"damage_type" : "刺伤"
]),
([	"action" : "$N一式「大雁啼沙」，全身贴地平飞，身剑合一，闪电般刺向$n的$l",
	"force" : 300,
	"dodge" : 10,
	"damage" : 70,
	"lvl" : 50,
	"skill_name" : "大雁啼沙",
	"damage_type" : "刺伤"
]),
([	"action" : "$N施出「进退龙游」，$w脱手飞出，如游龙般翱翔青宇，破空射向$n的$l",
	"force" : 350,
	"dodge" : 5,
	"damage" : 80,
	"lvl" : 60,
	"skill_name" : "进退龙游",
	"damage_type" : "刺伤"
]),
([	"action" : "$N长啸一声，一式「天地鹤翔」，腾空飞起，全身迸出无数道雪亮剑芒，照耀天际",
	"force" : 400,
	"dodge" : 0,
	"damage" : 90,
	"lvl" : 70,
	"skill_name" : "天地鹤翔",
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_combine(string combo) { return combo=="yanxing-dao"; }

int valid_learn(object me)
{
	return notify_fail(HIR"对不起，您的回风拂柳剑96-SR版已经过期，请升级到最新的版本。有\n"
			   "关讯息请到峨嵋弟子留言板处查询，或与客户服务部的静虚师太联系。\n"NOR);

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候太浅。\n");
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
	level   = (int) me->query_skill("huifeng-jian",1);
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
		return notify_fail("你的精力不够练回风拂柳剑。\n");
	if ( me->query_skill("huifeng-jian", 1) < 100 )
		me->receive_damage("jingli", 35);
	else
		me->receive_damage("jingli", 20);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}

