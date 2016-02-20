//Cracked by Roath
// hunyuan-zhang.c 混元掌
// qfy July 9, 1996

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N双掌内拱，续而向外疾推，一式「白云出岫」攻向$n的胸口",
	"force" : 145,
        "dodge" : 5,
	"parry" : 15,
	"damage_type" : "瘀伤",
	"lvl" : 0,
	"skill_name" : "白云出岫"
]),
([	"action" : "$N左掌虚抬，侧身转向，右掌斜穿而出，使出「白虹贯日」疾切$n的咽喉",
	"force" : 160,
        "dodge" : 5,
	"parry" : 15,
	"weapon": "右掌",
        "damage_type" : "劈伤",
	"lvl" : 12,
	"skill_name" : "白虹贯日"
]),
([	"action" : "$N使一式「云断秦岭」，转身抬肘，顶向$n的下腭",
	"force" : 180,
        "dodge" : 8,
	"parry" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 18,
	"skill_name" : "云断秦岭"
]),
([	"action" : "$N右掌抓向$n的$l，左拳凝劲后发，一式「青松翠翠」，企图混淆$n的攻势",
	"force" : 210,
        "dodge" : -5,
	"parry" : 15,
        "damage_type" : "瘀伤",
	"lvl" : 24,
	"skill_name" : "青松翠翠"
]),
([	"action" : "$N使出「天绅倒悬」，左腿后撑弹身而上，右拳护腰左拳自上而下猛然捶向$n$l",
	"force" : 245,
        "dodge" : 10,
	"parry" : 10,
        "damage_type" : "瘀伤",
	"lvl" : 30,
	"skill_name" : "天绅倒悬"
]),
([	"action" : "$N纵身跃起，一式「无边落木」，双掌幻出无数掌影，推向$n的周身各处",
	"force" : 290,
        "dodge" : 15,
	"parry" : 15,
        "damage_type" : "瘀伤",
	"lvl" : 36,
	"skill_name" : "无边落木"
]),
([	"action" : "$N左腿微曲右腿弓步，左拳护腰右掌下按，一招「高山流水」，按向$n的$l",
	"force" : 335,
        "dodge" : 10,
	"parry" : 15,
        "damage_type" : "瘀伤",
	"lvl" : 42,
	"skill_name" : "高山流水"
]),
([	"action" : "$N使一式「金玉满堂」，左掌护腰右掌直拍而出，劲气弥漫地挥向$n的$l",
	"force" : 370,
        "dodge" : 10,
	"parry" : 15,
        "damage_type" : "内伤",
	"lvl" : 48,
	"skill_name" : "金玉满堂"
]),
([	"action" : "$N两掌上下护胸，一式「风伴流云」，骤然身如流云化掌为剑，劈向$n$l",
	"force" : 400,
        "dodge" : 15,
	"parry" : 15,
        "damage_type" : "劈伤",
	"weapon": "双掌",
	"lvl" : 54,
	"skill_name" : "风伴流云"
]),
([	"action" : "$N一式「湮雨缥渺」，以身化剑，劲剧无伦地冲近$n，左掌护额，右掌直击$n的$l",
	"force" : 450,
        "dodge" : 10,
	"parry" : 10,
        "damage_type" : "内伤",
	"lvl" : 60,
	"skill_name" : "湮雨缥渺"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="pishi-poyu"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练混元掌必须空手。\n");
	if ((int)me->query_skill("zixia-gong", 1) < 20)
		return notify_fail("你的紫霞功火候不够，无法学混元掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练混元掌。\n");
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
	level = (int)me->query_skill("hunyuan-zhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练混元掌。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int time, level, old_time;

	if ( me->query_temp("wuji") ) {  
        	level = me->query_skill("hunyuan-zhang", 1);
        	old_time = victim->query_condition("hyz_damage");

		if ( victim->query_temp("last_enemy") != me->query("id") ) {
			victim->set_temp("last_enemy", me->query("id") );
			victim->delete("huashan/enemy");
		}

		if ( !victim->query("huashan/enemy") )
			victim->set("huashan/enemy", me->query_skill("hunyuan-zhang", 1)*3/4);

        	time = level/20 + old_time;
//		me->delete_temp("wuji");
		call_out("delete_wuji", 1, me);
        	victim->apply_condition("hyz_damage", time);
		tell_object(victim,HIR"你只觉得一股火热的内力袭入你的内腑，混身燥热无比！\n"NOR);
	}
}

void delete_wuji(object me) 
{
	me->delete_temp("wuji");
}
string perform_action_file(string action)
{
        return __DIR__"hunyuan-zhang/" + action;
}
