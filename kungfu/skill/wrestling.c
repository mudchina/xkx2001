//Cracked by Roath
//Ryu

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「骆驼扳」，左手抢着从$n腋下穿出，在$n的颈後用力扳落",
	"dodge" : 0,
	"damage" : 80,
        "damage_type" : "跌伤"
]),
([	"action" : "$N左手从$n胁下穿了上去，仰身上手，右手朝$n的$l扣下",
	"damage" : 70,
	"dodge" : -10,
        "damage_type" : "跌伤"
]),
([      "action" : "$N闷声不响，突然冲上前去，挺头往$n$l撞去",
        "damage" : 80,
	"dodge" : -10,
        "damage_type" : "内伤"
]),
([      "action" : "$N盘打扭跌，双手合抱住$n，借势上纵，已扭住$n的小腿，用力往下摔去",
        "damage" : 90,
	"dodge" : -20,
        "damage_type" : "跌伤"
]),
([      "action" : "$N一式「断山绞」，扳住$n後颈，纵声猛喝，双手互叉，用颈搭落",
        "damage" : 100,
	"dodge" : -10,
        "damage_type" : "跌伤"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	me->receive_damage("jingli", 30);
	return 1;
}

