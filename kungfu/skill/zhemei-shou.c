//Cracked by Kafei
//zhemei-shou.c 天山折梅手
//Xuanyuan

inherit SKILL;

mapping *action = ({
([      "action" : 
"$N大喝一声，使出一路迅猛的掌法，双掌上下翻飞、大开大阖，连续击向$n",
        "force" : 320,
        "parry" : 30,
        "dodge" : 30,
        "lvl"   : 10,
        "damage_type" : "瘀伤"
]),
([      "action" :
"$N足尖点地，御风而走，身形飘忽，掌力吞吐不定，突然间击向$n的$l，好一路潇洒自如的掌法",
        "force" : 260,
		"parry" : 30,
		"dodge" : 50,
        "lvl"   : 0,
        "damage_type" : "瘀伤"
]),
([      "action" :
"$N忽然变为一路沉稳掌法，双足踏实，右掌力刚阳，左掌力阴柔，刚柔并济，催动强大内力猛击$n的$l",
        "force" : 530,
        "parry" : 30,
		"dodge" : 5,
        "lvl"   : 80,
        "damage_type" : "内伤"
]),
([      "action" :
"$N双手忽而抓，忽而戳，忽而拳，忽而掌，连续变换数种小擒拿手法，向$n的$l抓去",
        "force" : 350,
        "dodge" : 45,
        "parry" : 5,
        "lvl"   : 30,
        "damage_type" : "抓伤"
]),
([      "action" :   
"$N使出一路大力擒拿手法，双手时而龙爪，时而虎爪，虎虎生风向$n的$l擒去",
        "force" : 380,
        "dodge" : 5,
        "parry" : 35,
        "lvl"   : 35,
        "damage_type" : "抓伤"
]),
([      "action" : 
"$N双手使鹰爪手，高扑低纵，上蹿下跳，向$n的手腕、脚腕、脖子，连出数爪擒拿",
        "force" : 400,
        "dodge" : 30,
        "parry" : 10,
        "lvl"   : 40,
        "damage_type" : "抓伤"
]),
([      "action" :
"$N拳风一变，双臂竟似没了骨头一般柔软曲折，使出一路鞭法向$n左右猛烈抽击",
        "force" : 450,
        "dodge" : 30,
        "parry" : 25,
        "lvl"   : 50,
        "damage_type" : "挫伤"
]),
([      "action" :
"$N五指并拢，化掌为刀，强劲内力运至掌缘，一招直劈$n的$l，深得刀法精要",
        "force" : 500,
        "dodge" : 30,
        "parry" : 30,
        "lvl"   : 72,
        "damage_type" : "挫伤"
]),
([      "action" :
"$N轻舒猿臂，双指并拢，相隔数尺之遥，纵身向$n当胸直刺，使的竟然是长枪枪法",
        "force" : 480,
        "dodge" : 40,
        "parry" : 10,
        "lvl"   : 90,
        "damage_type" : "挫伤"
]),
([      "action" :
"$N吐气开声，气灌丹田，右掌高举，五指回扣，化作一柄大斧，向$n当头爆劈",
        "force" : 550,
        "dodge" : 0,
        "parry" : 10,
        "lvl"   : 90,
        "damage_type" : "挫伤"
]),
([      "action" :
"$N发出一阵阴笑，双臂暴长，气运五指，使出一路兵器中的抓法，向$n连出数抓阴损招数",
        "force" : 520,
        "dodge" : 30,
        "parry" : 50,
        "lvl"   : 100,
        "damage_type" : "抓伤"
]),
([      "action" :
"$N一声长啸，化指为剑，使出一轮精妙的剑法绝招，向$n上下左右连刺带劈",
        "force" : 580,
        "dodge" : 30,
        "parry" : 30,
        "lvl"   : 100,
        "damage_type" : "挫伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("xiaowu-xiang", 1)<50
		&& (int)me->query_skill("bahuang-gong", 1)<50
		&& (int)me->query_skill("beiming-shengong", 1)<50)
		return notify_fail("你的逍遥派内功火候不够，无法学习天山折梅手。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法学习天山折梅手。\n");
	if ((int)me->query_skill("hand", 1) <80)
		return notify_fail("你的基本手法火候不够，无法学习天山折梅手。\n");
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
        level   = (int) me->query_skill("zhemei-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if (me->query_temp("weapon"))
		return notify_fail("练天山折梅手必须空手。\n");
	if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练天山折梅手。\n");
        me->receive_damage("jingli", 30, "精力透支过度死了。");
	return 1;
}

string perform_action_file(string action)
{
       return __DIR__"zhemei-shou/" + action;
}
