//Cracked by Roath
// emei-jian 峨嵋剑法
// xQin 10/99
//xiaojian fixed jue fight bug on May 25,2001

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action": "$N飞步上前，$w一抖，拦在$n面前，一招「虚式分金」，指着$p的$l，相距不到半寸，剑尖颤动不停",
	"force" : 120,
	"dodge" : 30,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "虚式分金",
	"damage_type": "刺伤"
]),
([	"action": "$N$w斜走，向上虚点，跟著使一招「顺水推舟」，$w向前一送，剑如电闪，疾向$n的$l刺去",
	"force" : 140,
	"dodge" : 20,
	"damage": 30,
	"lvl" : 10,
	"skill_name" : "顺水推舟",
	"damage_type": "刺伤"
]),
([	"action" : "$N身形一晃，抢上数丈，$w剑尖已指到$n身前，一招「金顶佛光」手起剑出，便向$n$l刺了过去",
	"force" : 170,
	"dodge" : 5,
	"damage" : 40,
	"lvl" : 20,
	"skill_name" : "金顶佛光",
	"damage_type": "刺伤"
]),
([	"action" : "$N身形微侧，已从$n身旁绕过，在这一瞬之间，向$p的$l斩了一剑，手法奇快，正是一招「烟斜雾横」",
	"force" : 200,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 30,
	"skill_name" : "烟斜雾横",
	"damage_type" : "割伤"
]),
([	"action" : "$N当下一招「月落西山」身随剑走，如电光般游到了$n身後，脚步未定，剑招先到，$w抖动，往$p$l刺去",
	"force" : 250,
	"dodge" : 5,
	"damage" : 60,
	"lvl" : 40,
	"skill_name" : "月落西山",
	"damage_type" : "刺伤"
]),
([	"action" : "但见寒芒吞吐，电闪星飞，$N一招「铁锁横江」推送而上，剑招凌厉之极，青霜到处，所向披靡",
	"force" : 300,
	"dodge" : 10,
	"damage" : 70,
	"lvl" : 50,
	"skill_name" : "铁锁横江",
	"damage_type" : "割伤"
]),
([	"action" : "蓦地里$N一声呼叱，纵身而出，舞动$w向$n急刺数剑，一招「金顶九式」，分向$n各处要穴刺去",
	"force" : 350,
	"dodge" : 5,
	"damage" : 80,
	"lvl" : 60,
	"skill_name" : "金顶九式",
	"damage_type" : "刺伤"
]),
([	"action" : "只见$N手腕一抖，一招「千峰竞秀」，$w挥动，如银蛇狂舞，剑招神光离合，偶尔虚实变幻，巧招忽生",
	"force" : 400,
	"dodge" : 0,
	"damage" : 90,
	"lvl" : 70,
	"skill_name" : "千峰竞秀",
	"damage_type" : random(2)?"刺伤":"割伤"
]),
([	"action": "但见$N身形穿插来去，剑法凌厉绝伦，东一刺，西一劈，展开「黑沼灵狐」，越打越快，竭力抢攻",
	"force" : 450,
	"dodge" : 10,
	"damage": 100,
	"lvl" : 80,
	"skill_name" : "黑沼灵狐",
	"damage_type" : random(2)?"刺伤":"劈伤"
]),
([	"action": "$N手齐鼻尖，使招「轻罗小扇」轻轻一颤，剑尖嗡嗡连响，自右至左、又自左至右的连晃九下，快得异乎寻常，但每一晃却又都清清楚楚",
	"force" : 500,
	"dodge" : 0,
	"damage": 110,
	"lvl" : 90,
	"skill_name" : "轻罗小扇",
	"damage_type": random(2)?"刺伤":"割伤"
]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("linji-zhuang", 1) < 20 )
		return notify_fail("你的临济十二庄火候太浅。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for( i = sizeof(action)-1; i >= 0; i-- )
		if( level >= action[i]["lvl"] )
			return action[random(i)]["skill_name"];
}

string *juejian_msg = ({ 
	"蓦地里$N$w疾闪，青光闪处，剑尖已指到了$n$l，恰似雷震电掣，剑招狠辣之极",
	"$N$w一晃，径往$n$l削去，剑势夭矫飞舞，忽分忽合，有如天神行法，凌厉无端",
	"却见$N飘身而上，半空中举剑上挑，剑光已封住了$n身周数尺之地，攻得精巧无比",
	"$N纵前抢攻，剑势如风，剑招愈来愈奇，$w颤动，飕飕飕向$n连环三剑，皆是极凌厉的攻势",
	"$N一个箭步纵到$n身前，手腕微颤，挥剑斜撩，横削$n$l，剑法极尽灵动轻捷",
});

mapping query_action(object me, object weapon)
{
	int i, level;
	object target;
	level = (int)me->query_skill("emei-jian", 1);

	// add checking target in the if condition, if there is no target,then don't use these special
	// jue attack msg,instead, the system will use normal attack msg.
	// xiaojian, May 25,2001

	target = me->select_opponent();

	if( me->query_temp("perform/juejian") && target )
	{
		return (["action": me->query_temp("perform/juejian") == 1 ?
				HIR"$N$w"HIR"微侧，第一招便即抢攻，剑尖直指$n丹田要穴，出手之凌厉猛悍，直是匪夷所思"NOR
				: juejian_msg[random(sizeof(juejian_msg))],
			 "force" : 500,
			 "dodge" : 50,
			 "damage": 250,
			 "damage_type": random(2)?"刺伤":"割伤" ]);
	}
	else for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("jingli") < 50 )
		return notify_fail("你的精力不够练峨嵋剑法。\n");

	if( me->query_skill("emei-jian", 1) < 100 )
		me->receive_damage("jingli", 35);
	else
		me->receive_damage("jingli", 20);

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"emei-jian/" + action;
}
