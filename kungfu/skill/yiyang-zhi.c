//Cracked by Roath
//yiyang-zhi.c

inherit SKILL;

string *parry_msg = ({
        "$n对$N的攻势视若不见，中指一伸，划向你的脉门。\n",
});
mapping *action = ({
([      "action" :
"$N身形向后飘出，左掌护胸，右手食指向前遥遥一挥，正是一招「鲁阳返日」",
        "force" : 250,
        "dodge" : 10,
        "parry" : 20, 
        "lvl"   : 0,
	 "weapon": "右手食指",
        "skill_name" : "鲁阳返日",
        "damage_type" : "刺伤"
]),
([      "action" :
"$N一式「无声无色」，施施然向前踏上半步，稍一侧身，右手拇指无声无息地点向$n的$l",
        "force" : 280,
        "dodge" : 10,
        "parry" : 30,
        "lvl"   : 15,
	"weapon": "右手拇指",
        "skill_name" :  "阳春白雪", 
        "damage_type" : "刺伤"
]),
([      "action" :
"$N面带微笑，左手食指若有若无、右手食指劲气逼人向着$n交叉点出，一式「双树枯荣」深得禅机",
        "force" : 350,
        "dodge" : 5,
        "parry" : 35,
        "lvl"   : 30,
	"weapon": "无形指力",
        "skill_name" :  "双树枯荣", 
        "damage_type" : "刺伤"
]),
([      "action" :   
"$N“嚯”地冲到$n的跟前，左手无名指一反一复连点两下，旋即退开，正是一式「阴阳交错」",
        "force" : 390,
        "dodge" : 25,
        "parry" : 5,
        "lvl"   : 35,
	"weapon": "左手无名指",
        "skill_name" :  "阴阳交错",
        "damage_type" : "刺伤"
]),
([      "action" : 
"$N身形陡然向上拔起，双手急点数下，一式「烈日骄阳」已将$n的全身要穴罩在指风之下",
        "force" : 450,
        "dodge" : 30,
        "parry" : 10, 
        "lvl"   : 40,   
	"weapon": "指风",
        "skill_name" :  "烈日骄阳",
        "damage_type" : "刺伤"
]),
([      "action" :
"$N吸气凝神，右手握住左腕，左手凭空出指，“哧”的一声指力破空点向$n，好一招「丹凤朝阳」！",
        "force" : 480,
        "dodge" : 30,
        "parry" : 25,
        "lvl" : 60,
	 "weapon": "指风",
        "skill_name" : "丹凤朝阳",
        "damage_type" : "刺伤"
]),
([      "action" :
"$N一式「非假非空」，双手低垂缩在袖中，小拇指轻出，$n正迟疑时，突觉两道凌厉劲气破空而至",
        "force" : 500,
        "dodge" : 30,
        "parry" : 30,
        "lvl" : 72,
        "weapon": "无形指力",
	"skill_name" : "非假非空",
        "damage_type" : "刺伤"
]),
([      "action" :
"$N脚下不丁不八站好，右手食指三曲三伸，指上劲力四溢，是一式「三阳开泰」遥点$n的$l",
        "force" : 530,
        "dodge" : 20,
        "parry" : 35,
        "lvl"   : 90,
	"weapon": "无形指力",
        "skill_name" : "三阳开泰",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || 
usage=="parry"; }
int valid_combine(string combo) { return combo=="qingyan-zhang" || 
combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query("gender") == "女性" && me->query_str() < 27)
		return notify_fail("你由于先天体质所限，无法修习一阳指。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练一阳指必须空手。\n");
	if ((int)me->query_skill("kurong-changong", 1)<80 
		&& (int)me->query_skill("beiming-shengong", 1)<80)
		return notify_fail("你的枯荣禅功火候不够，无法学一阳指。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
	if ((int)me->query_skill("finger", 1) <80)
		return notify_fail("你的基本指法火候不够，无法学一阳指。\n");
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
        level   = (int) me->query_skill("yiyang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练一阳指。\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiyang-zhi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if (random(me->query_skill("yiyang-zhi", 1)) > 100) {
		victim->apply_condition("yyz_damage", random(me->query_skill("yiyang-zhi", 1)/2)
			+ victim->query_condition("yyz_damage"));
		victim->set_temp("yyzenemy", me->query("id"));
	}
}

mapping *query_skilldbase() {return action;}
