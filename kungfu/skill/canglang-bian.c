//Cracked by Roath
// canglang.c
//chaos 22/3/97
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N伫立不动，挥动$w，使出一招「大海沉沙」，手中$w缓缓向$n的$l击去，去势虽不劲急，但鞭势沉滞，如同压了几千斤泥沙一般",
	"force" : 200,
	"dodge" : 0,
	"parry" : 5,
	"damage": 40,
	"lvl" : 0,
	"skill_name" : "大海沉沙",
	"damage_type" : "鞭伤"
]),
([      "action" : "$N手持$w中央，一招「海天一线」，$w一端陡然一翻，点向$n前胸，劲风所至，将$n退路封住，另一端如灵蛇出洞，疾速卷向$n脚踝",
	"force" : 220,
	"dodge" : 0,
	"parry" : 10,
	"damage": 50,
	"lvl" : 12,
	"skill_name" : "海天一线",
	"damage_type" : "鞭伤"
]),
([      "action" : "$N冷哼一声，急催内力，使出一招「巨浪排空」，鞭势加快，只见十数重鞭影如惊滔骇浪般向$n的$l疾卷而来",
	"force" : 250,
	"dodge" : 0,
	"parry" : 5,
	"damage": 60,
	"lvl" : 24,
	"skill_name" : "巨浪排空",
	"damage_type" : "刺伤"
]),
([      "action" : "$N缓缓转动手中$w，一式「万里无波」，手中$w去势奇慢，不带丝毫破空之声，但所过之处尘土飞扬，$w上所带劲风已刮得人扑面生疼",
	"force" : 280,
	"dodge" : 5,
	"parry" : 10,
	"damage": 70,
	"lvl" : 36,
	"skill_name" : "万里无波",
	"damage_type" : "鞭伤"
]),
([      "action" : "$N身形游走不定，忽地使出一招「沧海一粟」，$w上风声大作，刹那间数十条鞭影从四面八方向$n周身要害击到",
	"force" : 320,
	"dodge" : 10,
	"parry" : 5,
	"damage": 80,
	"lvl" : 48,
	"skill_name" : "沧海一粟",
	"damage_type" : "刺伤"
]),
([      "action" : "$N狂啸一声，双目精光大盛，一招「怒海蓝涛」，鞭势展开，或横扫直击，或盘旋翻卷，倾刻间已将$n全身裹住",
	"force" : 380,
	"dodge" : 15,
	"parry" : 15,
	"damage": 90,
	"lvl" : 60,
	"skill_name" : "怒海蓝涛",
	"damage_type" : "淤伤"
]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("bitao-xuangong", 1) < 30)
	{
		return notify_fail("你的碧涛玄功火候太浅。\n");
	}
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
	level   = (int) me->query_skill("canglang-bian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon, where;
	
	where = environment(me);
	
	if (!where->query("guanchao")) 
		return notify_fail("你练习了一会儿沧浪鞭法，发觉怎么也不能领会沧浪二字的精粹。\n");
	      
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 40)
		return notify_fail("你的精力不够练沧浪鞭法。\n");
	message_vision(HIC"$N面对海潮，徐徐挥鞭，使呼吸与海潮同步，渐渐感觉体内真气也如海潮澎湃一般无穷无尽。\n"NOR, me);
	me->add("neili", random(3));
	me->add("jingli", -30);
	return 1;
}
