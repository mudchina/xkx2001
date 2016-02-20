//Cracked by Roath
// feifeng-bian.c 飞凤鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$N沉肩滑步，手中$w一抖，使出一式「凤凰展翅」，$w迅捷无比地分打$n的左右两侧，$n顿时左右支绌，慌了手脚",
	"dodge":  5,
	"damage": 10,
	"force" : 120,
	"lvl" : 0,
	"skill_name" : "凤凰展翅",
	"damage_type":	"鞭伤"
]),
([	"action":"$N将身一纵，跃在半空，一式「彩凤栖梧」，手中$w盘旋而下，鞭势灵动之至，击向$n$l",
	"dodge":		 15,
	"damage":		 25,
	"force" : 		160,
	"lvl" : 		12,
	"skill_name" : "彩凤栖梧",
	"damage_type":	"鞭伤"
]),
([	"action":"$N轻叱一声，一招「鸾凤和鸣」，$N似乎纯系守势，但鞭势如抽丝剥茧，严密之极，将$n全身尽数罩在鞭影之中",
	"dodge":		30,
	"damage":		35,
	"force" : 		220,
	"lvl" : 		24,
	"skill_name" : "破云式",
	"damage_type":	"鞭伤"
]),
([      "action":"$N深吸一口气，将内力源源不绝地注入$w，蓦地使出一式「游龙戏凤」，$w矫夭飞舞，直如神龙破空一般，直刺$n$l",
        "dodge":                 40,
        "damage":                45,
        "force" :               260,
        "lvl" :                 36,
        "skill_name" : "游龙戏凤",
        "damage_type":  "鞭伤"
]),
([      "action":"$N一声清啸，连连舞动手中$w，正是一招「龙飞凤舞」，但见漫天鞭影铺天盖地地向$n卷来，势道猛烈之极",
        "dodge":                 50,
        "damage":                55,
        "force" :               320,
        "lvl" :                 60,
        "skill_name" : "龙飞凤舞",
        "damage_type":  "鞭伤"
]),
([      "action":"$N面露微笑，轻轻跨前一步，举手齐眉，缓缓使出一式「龙凤呈祥」，心中一片祥和，鞭势也平和中正，不带丝毫霸气，但却是沛然莫御",
        "dodge":                 60,
        "damage":                70,
        "force" :               360,
        "lvl" :                 72,
        "skill_name" : "龙凤呈祥",
        "damage_type":  "鞭伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	mapping fam;
	object weapon;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不足，没有办法练飞凤鞭法，多练些内力再来吧。\n");

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("你的枯荣禅功火候太浅。\n");

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
	level   = (int) me->query_skill("feifeng-bian",1);
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
		return notify_fail("你的精力不够练飞凤鞭法。\n");
	me->receive_damage("jingli", 25 );
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("feifeng-bian", 1) >= 10 )
		return __DIR__"feifeng-bian/" + action;
}

