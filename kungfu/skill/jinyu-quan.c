//Cracked by Roath
// jinyu-quan.c 金玉拳

inherit SKILL;

mapping *action = ({
([      "action" :
"$N身形晃动，双拳一前一后，一式「金光灿斓」，然击向$n的$l",
        "force" : 60,
        "dodge" : 0,
        "parry" : 5,
	 "damage": 0,
        "lvl" : 0,
        "skill_name" : "金光灿斓",
        "damage_type" : "瘀伤"
]), 
([      "action" :
"$N右手握拳，左手护胸，运足真气，一式「其利断金」，一拳击向$n",
        "force" : 130,
        "dodge" : 5,
        "parry" : 5,
         "damage": 15,
        "lvl" : 10,
        "skill_name" : "其利断金",
        "damage_type" : "瘀伤"
]),
([      "action" :
"$N一式「蓝田美玉」，纵身一跃，双拳齐出，猛的击向$n头顶",
        "force" : 195,
        "dodge" : 15,
        "parry" : 5,
         "damage": 20,
        "lvl" : 20,
        "skill_name" : "蓝田美玉",
        "damage_type" : "瘀伤"
]),
([      "action" :
"$N双拳平伸，双足猛一发力，一式「金玉其外」旋风般扑向$n",
        "force" : 250, 
        "dodge" : 15,
        "parry" : 25,
         "damage": 15,
        "lvl" : 30,
        "skill_name" : "金玉其外",
        "damage_type" : "瘀伤"
]),
([      "action" :
"$N身子一侧，重心移到右脚，全身重量压向右拳，一式「玉石俱焚」，忽的砸向$n的$l",
        "force" : 290,
        "dodge" : 5,
        "parry" : 30,
         "damage": 25,
        "lvl" : 40,  
        "skill_name" : "玉石俱焚",
        "damage_type" : "瘀伤"
]),
([      "action" :
"$N双手一扬，出了三个虚招，一式「金玉满堂」，忽然左拳从中部发力，击向$n的裆部",
        "force" : 320,
        "dodge" : 25, 
        "parry" : 20,
         "damage": 31, 
        "lvl" : 50,
        "skill_name" : "金玉满堂",
        "damage_type" : "瘀伤"
]),
([      "action" :
"$N一式「点石成金」，脚步一阵加快，猛的绕到$n的侧面，双拳用力砸向$n$l",
        "force" : 380, 
        "dodge" : 30,
        "parry" : 25,
         "damage": 38,
        "lvl" : 60,
        "skill_name" : "点石成金",
        "damage_type" : "瘀伤"
]),

([	"action" : 
"$N忽然双眼暴睁，双拳猛的加快，一式「众口铄金」顿时满天拳光，击向$n的面门",
	"force" : 430,
        "dodge" : 20,
	"damage": 50,
	"lvl" : 70,
	"skill_name" : "众口铄金",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qingyan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练金玉拳必须空手。\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20
		&& (int)me->query_skill("beiming-shengong", 1) < 20)
		return notify_fail("你的枯荣禅功火候不够，无法学金玉拳。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练金玉拳。\n");
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
	level   = (int) me->query_skill("jinyu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练金玉拳。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinyu-quan/" + action;
}
