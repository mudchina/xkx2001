//Cracked by Roath
// wuhu-duanmen. 五虎断门刀
// kane

inherit SKILL;

mapping *action = ({
([	"action" : "$N收刀入怀，一招「白虎跳涧」，凌空翻身一个腾跃，刀光自怀中向$n的$l直卷而下",
	"force" : 210,
      "dodge" : 10,
	"damage" : 20,
	"lvl" : 0,
	"skill_name" : "白虎跳涧",
	"damage_type" : "割伤"
]),
([	"action" : "$N刀势圈转，一招「剪扑自如」，刀尖不住颤动，幻起重重光浪，将$n团团罩住",
	"force" : 210,
      "dodge" : 10,
	"damage" : 30,
	"lvl" : 8,
	"skill_name" : "剪扑自如",
	"damage_type" : "割伤"
]),
([	"action" : "$N一声大喝，震得人耳鼓“嗡嗡”作响，顺势一刀斩下，刀未至，劲先到，正是一招「一啸生风」，",
	"force" : 210,
      "dodge" : 5,
	"damage" : 30,
	"lvl" : 16,
	"skill_name" : "一啸生风",
	"damage_type" : "割伤"
]),
([	"action" : "$N反手背刀，一招「负子渡河」，手中$w转个半圆，舞出一片刀花护住全身，蓦地向$n的$l直撅过去",
	"force" : 240,
      "dodge" : 15,
	"parry" : 15,
	"damage" : 40,
	"lvl" : 24,
	"skill_name" : "负子渡河",
	"damage_type" : "割伤"
]),
([	"action" : "$N收刀缩势，使一招「重节守义」，刀锋不离身周三尺，畜势以待，$n全身空门都在$N刀劲笼罩之下",
	"force" : 240,
      "dodge" : 20,
	"parry" : 20,
	"damage" : 40,
	"lvl" : 33,
	"skill_name" : "重节守义",
	"damage_type" : "割伤"
]),
([	"action" : "$N虎吼一声，横三刀，竖一刀，进手连环四刀，刚猛凌厉，无坚不摧，正是五虎断门刀中最威猛的「王字四刀」",
	"force" : 300,
      "dodge" : 5,
	"damage" : 60,
	"lvl" : 42,
	"skill_name" : "王字四刀",
	"damage_type" : "劈伤"
]),
([	"action" : "$N大呼酣斗，一招「雄霸群山」，刀势霸道已极，刀气四溢，漫天刀光向$n席卷而去",
	"force" : 300,
      "dodge" : 25,
	"damage" : 50,
	"lvl" : 51,
	"skill_name" : "雄霸群山",
	"damage_type" : "劈伤"
]),
([	"action" : "$N双目精光闪闪，刀中夹掌，正是一招「伏象胜狮」，掌击$n前胸，刀劈$n$l，掌力刀劲如怒潮倒灌，汹涌交错袭向$n",
	"force" : 300,
      "dodge" : 30,
	"damage" : 50,
	"lvl" : 60,
	"skill_name" : "伏象胜狮",
	"damage_type" : "劈伤"
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
/*
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候太浅。\n");
*/
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
	level   = (int) me->query_skill("wuhu-duanmen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练五虎断门刀。\n");
	me->receive_damage("jingli", 25);
	return 1;
}
