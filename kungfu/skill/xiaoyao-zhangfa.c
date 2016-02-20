//Cracked by Kafei
// xiaoyao-zhangfa
// 逍遥掌法。

inherit SKILL;

mapping *action = ({
([      "action": "只见身影一闪，$N双掌平平提到胸前，一前一后地推向$n的$l",
        "dodge": -30,
        "parry": 10,
        "force": 400,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形一转，飘在$n的身后，右掌猛地击向$n的$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "瘀伤"
]),
([	"action": "$N身形左一转，右一转，眼中精光四射，双掌闪电般地拍向$n的$l",
	"dodge": -10,
	"parry": -10,
	"force": 120,
	"damage_type": "瘀伤"
]),
([	"action": "$N微微一笑，似乎已经看出了$n的破绽，右掌隐隐带着风声拍向$n的$l",
        "dodge": -15,
	"parry": -10,
	"force": 160,
	"damage_type": "瘀伤"
]),
([	"action": "$N袖子在内力鼓荡下微微扬起，一声长啸，双掌雷霆般地推向$n的$l",
	"dodge": -10,
	"parry": 10,
	"force": 200,
	"damage_type": "瘀伤"
]),
([	"action": "$N退后一步，右掌插腰，左掌轻飘飘地劈向$n的$l",
	"dodge": -10,
	"parry": 20,
	"force": 250,
	"damage_type": "瘀伤"
]),
([	"action": "$N猛地跃起，身形在空中一转，右掌从不可能的角度向$n推出",
	"dodge": 0,
	"parry": 10,
	"force": 100,
	"damage_type": "瘀伤"
]),
([	"action": "$N缓缓地吸了一口气，双掌举起，一阴一阳的拍向$n的$l",
	"dodge": -25,
	"parry": -10,
	"force": 300,
	"damage_type": "瘀伤"
]),
([	"action": "$N向后一闪，漫不经心地向$n的$l连拍数掌",
	"dodge": -20,
	"parry": -20,
	"force": 230,
	"damage_type": "瘀伤"
]),
([	"action": "$N身子滴溜溜地一转，左掌一立，右掌飞快地按向$n的$l",
	"dodge": -10,
	"parry": 20,
	"force": 160,
	"damage_type": "瘀伤"
]),
([	"action": "$N双眉微扬，脸上红色一现，左掌击向$n的$l，跟着右掌推出，将两股力并在一起",
	"dodge": -20,
	"parry": 30,
	"force": 250,
	"damage_type": "瘀伤"
]),
([	"action": "$n只见眼前一花，$N身子一摆，右掌由下往上击向$n的$l",
	"dodge": -25,
	"parry": 1,
	"force": 320,
	"damage_type": "瘀伤"
]),
([	"action": "$N身行一飘，有若神仙，右掌需晃，左掌按向$n的$l",
	"dodge": -15,
	"parry": 40,
	"force": 200,
	"damage_type": "瘀伤"
]),
([	"action": "$N左一飘，右一闪，衣襟在风中微微飘扬，左掌贴在背后，右掌唰得击向$n的$l",
	"dodge": -10,
	"parry": 40,
	"force": 220,
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练逍遥掌法必须空手。\n");
	if ((int)me->query_skill("shenhuo-xuanming", 1) < 20)
		return notify_fail("你的圣火玄冥功火候不够，无法练逍遥掌法 。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练逍遥掌法。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练逍遥掌法。\n");
	me->add("jingli", -30, "精力透支过度死了");
	me->add("neili", -5);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"xiaoyao-zhangfa/" + action;
}
