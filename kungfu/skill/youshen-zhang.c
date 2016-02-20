//Cracked by Roath
// jinshe-z.c
// 金蛇游身掌
// A.P. 11.12.1996

inherit SKILL;

mapping *action = ({
([      "action": "$N足踏蛇行步，双掌上下翻飞，使出「千蛇出洞」，向$n连续拍出",
	"dodge": 0,
	"force": 140,
	"lvl"  : 0,
	"damage_type": "瘀伤"
]),
([      "action": "$N使出「大沼龙蛇」，身影晃动，一掌大力劈山之势向$n的$l劈下",
	"dodge": 5,
	"force": 160,
	"lvl"  : 5,
	"damage_type": "瘀伤"
]),
([      "action": "$N发出一声冷喝「哼！」，双掌由外向里合击，「双蛇抢珠」，斩向$n头部两侧",
	"dodge": -5,
	"force": 180,
	"lvl"  : 10,
	"damage_type": "瘀伤"
]),
([      "action": "$N施出一招「游走式」，踏起蛇形步绕着$n转圈儿，令$n眼花缭乱，同时极快地连劈数掌",
	"dodge": 10,
	"force": 200,
	"lvl"  : 15,
	"damage_type": "瘀伤"
]),
([      "action": "$N左手对空划动着，右掌运足内力缓缓推出，一招「盘身式」，推向$n的$l",
	"dodge": 0,
	"force": 220,
	"lvl"  : 20,
	"damage_type": "瘀伤"
]),
([      "action": "$N突然身行一伏贴近地面，双掌并立，一式「金蛇吐衅」，有如鬼魅地拍上了$n的小腹",
	"dodge": 5,
	"force": 250,
	"lvl"  : 25,
	"damage_type": "瘀伤"
]),
([      "action": "$N身子一侧从$n的右腋下钻过，使出「金蛇翻嗤」，右掌反手向后大力一挥击向$n$l",
	"dodge": 10,
	"force": 280,
	"lvl"  : 30,
	"damage_type": "劈伤"
]),
([      "action": "$N使出「杯弓蛇影」，右掌向右一挥似劈向$n，左掌却无声无息地拍上了$n的$l",
	"dodge": 5,
	"force": 310,
	"lvl"  : 35,
	"damage_type": "内伤"
]),
([      "action": "$N使出「金蛇缠丝手」，双臂成不可思议的扭曲状，绕过$n的招架，拍上了$n的$l",
	"dodge": 0,
	"force": 340,
	"lvl"  : 40,
	"damage_type": "瘀伤"
]),
([      "action": "$N身形如蛇般滑动，使出「灵蛇游八方」从对手招式的空隙中从容穿过，双掌一错，按向$n的$l",
	"dodge": 15,
	"force": 370,
	"lvl"  : 45,
	"damage_type": "瘀伤"
]),
([      "action": "$N挺身直立，右掌高举，自上而下，一招「金蛇探头」，拍向$n的$l",
	"dodge": 5,
	"force": 410,
	"lvl"  : 52,
	"damage_type": "内伤"
]),
([      "action": "$N施展「金龙升天」纵身向前一窜，飞起在半空中，双掌暗带风雷，呼啸地击向$n的头顶",
	"dodge": 20,
	"force": 450,
	"lvl"  : 60,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金蛇游身掌必须空手。\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("你的内功火候不够，无法练金蛇游身掌。\n");

	if ((int)me->query_int() < 30)
		return notify_fail("你的悟性不够，无法领悟金蛇游身掌。\n");

	if ((int)me->query_con() < 20)
		return notify_fail("你的根骨不够，无法练金蛇游身掌。\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练金蛇游身掌。\n");
	
	if (!present("jinshe miji", me)) 
		return notify_fail("练习金蛇游身掌必须一面研读《金蛇密籍》。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("youshen-zhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练金蛇游身掌。\n");

	me->receive_damage("jingli", 25, "精力透支过度死了");
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"youshen-zhang/" + action;
}