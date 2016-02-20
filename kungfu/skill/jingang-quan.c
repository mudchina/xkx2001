//Cracked by Roath
// jingang-quan.c -大金刚拳

inherit SKILL;

mapping *action = ({
([	"action" : "$N盘膝而坐，二手合十，一式「莲花座」，双拳蓄势而发，击向$n的$l",
	"force" : 180,
        "dodge" : -5,
	"lvl" : 0,
	"skill_name" : "莲花座",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一式「烈火锥」，双掌轮流下击，拳势如焰，吡啪爆响",
	"force" : 200,
        "dodge" : 5,
	"damage": 10,
	"lvl" : 10,
	"skill_name" : "烈火锥",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N腾空飞起，一式「八方雨」，双手双腿齐出，令$n无可躲藏",
	"force" : 230,
        "dodge" : 15,
	"damage": 10,
	"lvl" : 20,
	"skill_name" : "八方雨",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双掌虚含，掌缘下沉，一式「掌心雷」，缓缓向$n推出",
	"force" : 270,
        "dodge" : 5,
	"damage": 20,
	"lvl" : 30,
	"skill_name" : "掌心雷",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一臂前伸，一臂后指，一式「五指山」，攻向$n的身前身后",
	"force" : 320,
        "dodge" : 10,
	"damage": 15,
	"lvl" : 40,
	"skill_name" : "五指山",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「观音渡」，两手十指虚点$n的全身三十六道要穴",
	"force" : 380,
        "dodge" : 25,
	"damage": 25,
	"lvl" : 48,
	"skill_name" : "观音渡",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两目内视，双手内笼，一式「天龙唱」，四面八方响起震人心魄的龙吟",
	"force" : 450,
        "dodge" : 15,
	"damage": 35,
	"lvl" : 54,
	"skill_name" : "天龙唱",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸",
	"force" : 530,
        "dodge" : 20,
	"damage": 50,
	"lvl" : 60,
	"skill_name" : "如来笑",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练大金刚拳必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候不够，无法学大金刚拳。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练大金刚拳。\n");
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
	level   = (int) me->query_skill("jingang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练大金刚拳。\n");

        if( (int)me->query_skill("qianye-shou", 1) < 100 )
                return notify_fail("你的如来千叶手修为还不够。\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jingang-quan/" + action;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("jingang-quan", 1) >= 150
        &&  !me->query("sl_gifts/jgq") ) {
                me->add("str", 1);
                me->set("sl_gifts/jgq", 1);
                write("\nn你的大金刚拳学有所成，提高了你的臂力。\n");
        }
}
        
