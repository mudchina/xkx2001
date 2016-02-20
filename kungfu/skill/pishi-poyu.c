//Cracked by Roath
// pishi-poyu.c 劈石破玉拳
// qfy September 28, 1996.

inherit SKILL;

mapping *action = ({
([      "action" : "$N施展「起手式」，身子微躬、右拳左掌合着一揖，突然随势向前疾探，打向$n$l",
        "force" : 150,
        "dodge" : 5,
	"parry" : 10,
        "lvl" : 0,
        "skill_name" : "起手式",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左掌虚抚使出「石破天惊」，右拳“嗖”地一声从掌风中猛穿出来，击向$n的$l",
	"force" : 200,
        "dodge" : -5,
	"parry" : 15,
	"lvl" : 10,
	"skill_name" : "石破天惊",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N气沉丹田，身向前俯，双掌「铁闩横门」，带着隐隐风雷之声缓缓地推向$n",
	"force" : 240,
        "dodge" : 10,
	"parry" : 10,
	"lvl" : 20,
	"skill_name" : "铁闩横门",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N腾空飞起，一式「千斤坠地」，对着$n雷霆般地猛捣数拳，拳风猛烈重如山",
	"force" : 280,
        "dodge" : 15,
	"parry" : 10,
	"lvl" : 30,
	"skill_name" : "千斤坠地",
        "damage_type" : "瘀伤"
]),
([	"action" : "忽然$n转到$N身后，$N一式「傍花拂柳」，守中带攻的背对反手一拳迅捷回击",
	"force" : 320,
        "dodge" : 10,
	"parry" : 15,
	"lvl" : 38,
	"skill_name" : "傍花拂柳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N闪电般一招「金刚挚尾」，急冲到$n身前，抓向膻中大穴，欲将$n提起丢掷",
	"force" : 360,
        "dodge" : 15,
	"parry" : 10,
	"lvl" : 45,
	"skill_name" : "金刚挚尾",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双拳连捣，使出「封闭手」，带动重重拳影，翻山蹈海般地盖向$n周身上下",
	"force" : 400,
        "dodge" : 15,
	"parry" : 10,
	"lvl" : 55,
	"skill_name" : "封闭手",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N拳势如雷似电，一式「粉石碎玉」，荡起虎虎拳风，力拔千钧的笔直捣往$n$l",
	"force" : 450,
        "dodge" : 15,
	"parry" : 15,
	"lvl" : 65,
	"skill_name" : "粉石碎玉",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="hunyuan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练劈石破玉拳必须空手。\n");
	if ((int)me->query_skill("zixia-gong", 1) < 20)
		return notify_fail("你的紫霞功火候不够，无法学劈石破玉拳。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练劈石破玉拳。\n");
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
	level   = (int) me->query_skill("pishi-poyu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练劈石破玉拳。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"hunyuan-zhang/" + action;
}
