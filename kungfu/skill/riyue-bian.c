//Cracked by Roath
// riyue-bian.c 日月鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N端坐不动，一招「裂石式」，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭",
	"dodge":		-5,
	"damage":		60,
	"force" : 		160,
	"lvl" : 		0,
	"skill_name" : "裂石式",
	"damage_type":	"鞭伤"
]),
([	"action":		"$N身形一转，一招「断川式」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
	"dodge":		-10,
	"damage":		 95,
	"force" : 		320,
	"lvl" : 		60,
	"skill_name" : "断川式",
	"damage_type":	"鞭伤"
]),
([	"action":		"$N力贯鞭梢，一招「破云式」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
	"dodge":		-15,
	"damage":		120,
	"force" : 		480,
	"lvl" : 		90,
	"skill_name" : "破云式",
	"damage_type":	"鞭伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	mapping fam;
	object weapon;

	fam = me->query("family"); 
	if( !mapp(fam) || fam["family_name"] != "少林派" )
		return notify_fail("你不属于少林派，不能学习博大精深的日月鞭法！\n");

	if ( fam["family_name"] == "少林派" && fam["generation"] > 36 )
		return notify_fail("你资格不够，不能学习日月鞭法，等到升了辈份再说吧。\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力不足，没有办法练日月鞭法，多练些内力再来吧。\n");

	if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
		return notify_fail("你的混元一气功火候太浅。\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

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
	level   = (int) me->query_skill("riyue-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练日月鞭法。\n");
	me->receive_damage("jingli", 10 );
	if( me->query_skill("riyue-bian",1) > 150 ) me->receive_damage("jingli", 5 );
	if( me->query_skill("riyue-bian",1) > 180 ) me->receive_damage("jingli", 10 );
	if( me->query_skill("riyue-bian",1) > 200 ) me->receive_damage("jingli", 15 );

	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
		return __DIR__"riyue-bian/" + action;
}

