//Cracked by Roath
// huoyan-dao 火焰刀
// qfy, chage, paoshou Sept 26, 1996
// Ryu, 11/14/96.
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N双掌相对虚搓了几下，突然大喝一声，双掌一式「钻木取火」，激起一片热浪攻向$n$l",
	"force" : 350,
        "dodge" : 70,
	"parry" : 10,
	"damage" : 30,
	"weapon": "气浪",
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "钻木取火"
]),
([	"action" : "紧接着$N使出「祝融怀焰」，双手如抱圆球，内力运处，一股炙热无形刀气斩向$n的$l",
	"force" : 380,
        "dodge" : 60,
	"parry" : 10,
	"damage" : 35,
	"weapon": "无形刀气",
        "damage_type" : "割伤",
	"lvl" : 12,
	"skill_name" : "祝融怀焰"
]),
([	"action" : "$N使一式「风火无边」，左掌立刃大开大阖，右掌飘忽灵动，将$n拢罩在灼炙的刀风之下",
	"force" : 400,
        "dodge" : 70,
	"parry" : 10,
	"damage" : 40,
	"weapon": "无形刀气",
        "damage_type" : "割伤",
	"lvl" : 24,
	"skill_name" : "风火无边"
]),
([      "action" : "$N口念轮回经，长吸了一口气，右掌如刀切斧凿，一式「六道轮回」，携着气浪照$n周身连劈六刀", 
        "force" : 420,
        "dodge" : 60,
	"damage" : 45,
	"parry" : 10,
	"weapon": "气浪",
        "damage_type" : "割伤",
        "lvl" : 36,
        "skill_name" : "六道轮回"
]),
([	"action" : "只见$N面色凝重，施展「双龙吐焰」，双掌缓缓推出，两股炙灼的内力猛然直袭$n的$l",
	"force" : 430,
	"parry" : 10,
        "dodge" : 50,
	"damage" : 50,
	"weapon": "气浪",
        "damage_type" : "内伤",
	"lvl" : 48,
	"skill_name" : "双龙吐焰"
]),
([	"action" : "$N面带笑容使出「刀山火海」，身形微侧，手掌从袖底穿出，挟两股极热的劲力劈向$n",
	"force" : 450,
        "dodge" : 40,
	"parry" : 10,
	"damage" : 60,
	"weapon": "气浪",
        "damage_type" : "割伤",
	"lvl" : 60,
	"skill_name" : "刀山火海"
]),
([      "action" : "$N左手捧人颅式，身形一展「白佛光度」，右掌一刀劈空向$n的$l砍去",
        "force" : 480,
        "dodge" : 30,
	"parry" : 10,
	"damage" : 70,
	"weapon": "无形刀气",
        "damage_type" : "割伤",
        "lvl" : 72,
        "skill_name" : "白佛光度"
]),
([	"action" : "$N跃起一式「火内莲花」，左掌连劈，沸腾的劲力罩住$n的身子，右掌紧扬，一刀斩向$n顶门",
	"force" : 530,
        "dodge" : 40,
	"parry" : 10,
	"damage" : 90,
	"weapon": "气浪",
        "damage_type" : "割伤",
	"lvl" : 84,
	"skill_name" : "火内莲花"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练火焰刀必须空手。\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20)
		return notify_fail("你的龙象舨若功火候不够，无法学火焰刀。\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力太弱，无法练火焰刀。\n");
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
	level = (int)me->query_skill("huoyan-dao", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

//	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练火焰刀。\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
string perform_action_file(string action)
{
        if ( this_player()->query_skill("huoyan-dao", 1) >= 50 )
                return __DIR__"huoyan-dao/" + action;
}
