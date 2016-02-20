//Cracked by Roath
//qishang-quan.c 七伤拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N暗运几口真气，跨上一步，臂骨格格作响，劈的一声，一拳打向$n$l",
	"force" : 380,
        "parry" : 5,
	"damage": 50,
	"lvl" : 0,
        "damage_type" : "内伤"
]),
([	"action" : "$N深吸一口长气，脸如金纸，双掌一错隐隐发出金铁交鸣之声，＂锵＂的一声轰向$n的$l",
	"force" : 400,
        "parry" : 5,
	"damage": 80,
	"lvl" : 10,
        "damage_type" : "内伤"
]),
([	"action" :"$N身法凝滞，一拳徐徐推向$n，忽地关节一扭，手臂暴长半尺，拳风如木魅夜啼，厉啸声中击向$n的$l",
	"force" : 430,
        "parry" : 15,
	"damage": 80,
	"lvl" : 20,
        "damage_type" : "内伤"
]),
([	"action" :"$N大喝一声，双拳连环虚击，风声未起，拳上暗劲已如怒潮倒灌，海啸逆卷，袭向$n",
	"force" : 470,
        "parry" : 5,
	"damage": 80,
	"lvl" : 30,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N嗔目大喝，宛如晴天霹雳，一拳轰出，拳风炽热如焰，空气竟发出＂噼啪＂爆裂之声，压向$n的$l",
	"force" : 420,
        "parry" : 10,
	"damage": 85,
	"lvl" : 40,
        "damage_type" : "内伤"
]),
([	"action" : "$N双臂一沉一扬，拳如巨刃开山，划出一道如狱气壁，直逼向$n，$n胸口一紧，只觉烦恶欲呕",
	"force" : 480,
        "parry" : 25,
	"damage": 80,
	"lvl" : 50,
        "damage_type" : "内伤"
]),
([	"action" : "$N双目微阖，步法飘忽，轻飘飘击出数拳，却是半点声息也无，$n蓦地察觉微风拂体，拳上阴劲已袭向$l",
	"force" : 550,
        "parry" : 15,
	"damage": 135,
	"lvl" : 60,
        "damage_type" : "内伤"
]),
([	"action" : "$N一声狂啸，双目赤红，拳路大开大阖，每一拳击出如诸神震怒，石破天惊，皆含催破内家真气的大威力",
	"force" : 600,
        "parry" : 20,
	"damage": 100,
	"lvl" : 70,
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练七伤拳必须空手。\n");
	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够，无法学七伤拳。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练七伤拳。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("qishang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练七伤拳。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	if( me->query_skill("force") < 250 
	|| me->query_skill("qishang-quan", 1) < 180 ) {
		me->apply_condition("qs_self_damage", me->query_condition("qs_self_damage") + random(5));
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("qishang-quan", 1)) > 80 ) {
                victim->apply_condition("qs_damage",
                random(me->query_skill("qishang-quan", 1)/3) + victim->query_condition("qs_damage"));
        }

	if ( victim->query_temp("jinzhongzhao") ) {
		victim->apply_condition("qs_damage", victim->query_condition("qs_damage")/3);
	}
}

/*
string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}
*/
