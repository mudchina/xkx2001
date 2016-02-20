//Cracked by Roath
// Duanjia-jian 段家剑
// Original, unknown; modified, by Acep

inherit SKILL;

mapping *action = ({
([      "action" :
"$N右手一转，一式「云横秦岭」手中$w平指，左右连续摆动，一气呵成横扫$n的$l",
        "force" : 125,
        "dodge" : 5,
	"parry" : 15,
        "damage": 5,
        "lvl"   : 0,
        "skill_name" : "云横秦岭",
        "damage_type" : "劈伤"

]),
([      "action" :
"$N身子一侧，右足前踏，使出一式「飞流直下」手中$w急劈$n的$l",
        "force" : 150,
        "dodge" : 0,
		"parry" : 15,
        "damage": 10,
        "lvl"   : 10,
        "skill_name" : "飞流直下",
        "damage_type" : "劈伤"

]),
([      "action" :
"$N仗$w一横，一式「雪涌蓝关」，双手运足真力，从右往左向$n拦腰一斩",
        "force" : 180,
        "dodge" : 5,
		"parry" : 15,
        "damage": 20,
        "lvl"   : 20,

        "skill_name" : "雪涌蓝关",
        "damage_type" : "劈伤"

]),
([      "action" :
"“呼”的一声风响，$N纵身跃起在半空，一式「高山流水」，$w凌空劈向$n",
        "force" : 230,
        "dodge" : 25,
		"parry" : 5,
        "damage": 30,
        "lvl"   : 30,
        "skill_name" : "高山流水",
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type" : "劈伤"

]),
([      "action" :
"$N仰天一笑，一式「碧鸡报晓」，手中先$w向上虚空一挑，转而向$n的$l点去",
        "force" : 250,
        "dodge" : 15,
		"parry" : 15,
        "damage": 40,
        "lvl"   : 40,
        "skill_name" : "碧鸡报晓",
        "damage_type" : "刺伤"
]),
([      "action" :
"$N使出一式「奇兵突起」，步法忽然一缓，右手$w缓缓推出,忽的在$n迟疑之际以十倍速度刺向$n的$l",
        "force" : 280,
        "dodge" : 5,
		"parry" : 0,
        "damage": 50,
        "lvl"   : 50,
        "skill_name" : "奇兵突起",
        "damage_type" : "刺伤"
]),
([      "action" : 
"$N挺胸舒臂，左手捏个剑诀，右手$w轻挥，刺向$n的$l，正是段家剑的起手势「其利断金」",
        "force" : 300,
        "dodge" : 10,
		"parry" : 0,
        "damage": 60,
        "lvl"   : 60,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "其利断金",
        "damage_type" : "刺伤"
]),
([      "action" :  
"$N飞身一跃，一式「金马横空」，在半空中转身，反手一挥，$w横飞而出，直刺$n的$l",
        "force" : 320,
        "dodge" : 25,
		"parry" : 10,
        "damage": 65,
        "lvl"   : 70,
        "skill_name" : "金马横空",
        "damage_type" : "刺伤"
]),
([      "action" :
"$N忽然团身一缩，手中$w乍然一现，一式「雨打梨花」，漫天劲气如水银泄地般点向$n",
        "force" : 350,
        "dodge" : 5,
		"parry" : 30,
        "damage": 75,
        "lvl"   : 80,
		"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "雨打梨花",
        "damage_type" : "刺伤"
]),
([      "action" :   
"$N全身运气，手中$w暴增三尺，一式「逐鹿中原」以迅雷不及掩耳之势暴劈$n的$l",
        "force" : 380,
        "dodge" : 5,
		"parry" : 25,
        "damage": 85,
        "lvl"   : 90,
		"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "逐鹿中原",
        "damage_type" : "劈伤"

]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == 
"parry") || (usage == "staff"); }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20
		&& (int)me->query_skill("beiming-shengong", 1) < 20)
		return notify_fail("你的枯荣禅功火候太浅。\n");
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
	level=(int) me->query_skill("duanjia-jian",1);
    for(i=sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
		return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword" 
		&& (string)weapon->query("skill_type") != "staff")
		return 
		notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不足。\n");
	me->receive_damage("jingli", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"duanjia-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weapon;
	if (random(me->query_skill("yiyang-zhi", 1)) > 80
		&& objectp(weapon = me->query_temp("weapon"))
		&& weapon->query("skill_type")=="staff"
		&& weapon->query_temp("yiyang")) {
		victim->apply_condition("yyz_damage", random(me->query_skill("yiyang-zhi", 1)/2) + 
			victim->query_condition("yyz_damage"));
        victim->set_temp("yyzenemy", me->query("id"));
	}
}
