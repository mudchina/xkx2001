//Cracked by Roath
//Jay 10/7/96
// modified by sdong to add some damage 10/25/98
// modified by maco again 2/9/2000

#include "ansi.h"
inherit SKILL;

mapping *action = ({
([	"action": "$N使出一招「灵蛇出洞」，手中$w倏伸倏缩，直取$n的$l",
        "force" : 100,
        "dodge" : 10,
        "damage" : 15,
        "lvl" : 0,
	"damage_type": "刺伤"
]),
([	"action": "$N手中$w左右晃动，一招「摇头摆尾」向$n的$l攻去",
	"force" : 120,
	"dodge":  0,
	"damage": 30,
	"lvl" : 0,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "瘀伤"
]),
([	"action": "$N举起$w，居高临下使一招「灵蛇下涧」敲向$n的$l",
        "force" : 160,
	"dodge":  10,
	"damage": 40,
	"lvl" : 10,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "挫伤"
]),
([	"action": "$N施出「灵蛇挺身」，$w杖尾在地上重重一登，由下往上向$n撩去",
        "force" : 240,
	"dodge":  20,
	"damage": 60,
        "lvl" : 20,
	"damage_type": "擦伤"
]),
([      "action": "$N突然挺身倒下，手中$w一招「蛇游蟒走」，贴着地皮缠向$n的$l",
        "force" : 300,
        "dodge":  20,
        "damage": 70,
	"lvl" : 30,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "瘀伤"
]),
([      "action": "$N忽然浑身抽动，一招「蛇缠左右」，杖风四方八面拦住$n，手中$w击向$n的周身大穴",
	"force" : 350,
	"dodge":  5,
	"damage": 80,
	"lvl" : 40,
	"damage_type": "瘀伤"
]),
([      "action": "$N的身体突然向前扑倒，使出「巨蟒下山」，手中$w劈头砸向$n，杖头未至，一股劲风已将$n逼得难以喘气",
	"force" : 400,
	"dodge":  0,
	"damage": 100,
	"lvl" : 50,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "挫伤"
]),
([      "action": "$N猛地把$w抛向地面，$w从地下反弹，击$n于意料之外，正是一招「蛇行雷电」",
	"force" : 440,
	"dodge":  10,
	"damage": 120,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"lvl" : 60,
	"damage_type": "刺伤"
]),

});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功功火候太浅。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("staff")) > 60
	&& me->query_skill("force") > 90
	&& me->query("neili") > 120 && random(2) == 0) {
		return ([
		"action": HIB"$N突然双手撑地，双足夹住$w"+HIB"，裹着一阵风声打向$n"NOR,
		"force" : 500,
		"damage": 150,
		"damage_type": "瘀伤"]);
	}

	return action[random(sizeof(action))];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if (random(me->query_skill("lingshe-zhang",1))>30
		  && (me->query_temp("weapon"))->query("name")=="蛇杖") {
		victim->apply_condition("snake_poison",
					 random(me->query_skill("lingshe-zhang", 1)/2) +
		victim->query_condition("snake_poison"));
	if (victim->query("poisoner") != me)
		victim->set("poisoner", me);
        }
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练灵蛇杖法。\n");
	me->receive_damage("jingli", 40);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lingshe-zhang/" + action;
}

