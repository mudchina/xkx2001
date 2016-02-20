//Cracked by Roath
// yizhi-chan.c 一指禅

inherit SKILL;

mapping *action = ({
([	"action" : "$N双指并拢，一式「佛恩济世」，和身而上，左右手一前一后戳向$n的胸腹间",
	"force" : 60,
        "dodge" : -5,
        "parry" : -5,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "佛恩济世",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左掌护胸，一式「佛光普照」，右手中指前后划了个半弧，猛地一甩，疾点$n的$l",
	"force" : 120,
        "dodge" : 10,
        "parry" : 15,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "佛光普照",
        "damage_type" : "刺伤"
]),
([	"action" : "$N身形闪动，一式「佛门广渡」，双手食指端部各射出一道青气，射向$n的全身要穴",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 60,
	"lvl" : 40,
	"skill_name" : "佛门广渡",
        "damage_type" : "刺伤"
]),
([	"action" : "$N盘膝跌坐，一式「佛法无边」，左手握拳托肘，右手拇指直立，遥遥对着$n一捺",
	"force" : 480,
        "dodge" : 40,
        "parry" : 30,
	"damage": 90,
	"lvl" : 60,
	"skill_name" : "佛法无边",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="banruo-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一指禅必须空手。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学一指禅。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练一指禅。\n");
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
	level   = (int) me->query_skill("yizhi-chan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练一指禅。\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("你的般若掌修为还不够。\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yizhi-chan/" + action;
}

void skill_improved(object me)
{
        int level = (int)me->query_skill("yizhi-chan", 1);

        if( level
        &&  (int)me->query_skill("yizhi-chan", 1) >= 180
        &&  !me->query("sl_gifts/yzc") ) {
                me->add("con", 1);
                me->set("sl_gifts/yzc", 1);
                write("\n你的一指禅和般若掌学有所成，提高了你的根骨。\n");
        }

        if( !(level % 10) && level >= (int)me->query_skill("hunyuan-yiqi", 1) ) {
                me->improve_skill("hunyuan-yiqi", (level - 5), 1);
                write("\n你在一指禅方面的造诣增进了你的混元一气功修为。\n");
        }
}
