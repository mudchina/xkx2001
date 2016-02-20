//Cracked by Roath
// yanxing-dao.c 雁行刀法

inherit SKILL;

mapping *action = ({
([	"action" : "$N默念「让字诀」，迅速闪开$n的攻势，$w同时随身法向$n的$l挥出",
	"force" : 120,
	"dodge" : 15,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "让字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N坐闪右让，一招「打字诀」，手中$w直出，出其不意地打向$n的面部",
	"force" : 130,
	"dodge" : 10,
	"damage": 20,
	"lvl" : 5,
	"skill_name" : "打字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N刀含「顶字诀」，$w先发后至，预先堵住了$n企图发出的招式",
	"force" : 140,
	"dodge" : 15,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "顶字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N故示其弱，一招「引字诀」，乘$n信以为真时，猛地挥动$w向$n的$l斩去",
	"force" : 160,
	"dodge" : 15,
	"damage": 30,
	"lvl" : 15,
	"skill_name" : "引字诀",
	"damage_type" : "割伤",
]),
([	"action" : "$N手捏「套字诀」，撤步套让，传身而走，诱$n追击，乘其不备向后猛击",
	"force" : 180,
	"dodge" : 30,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "套字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N侧身对敌，脚站方园，一招「陈字诀」，$w无行无定，似功似守，令$n无所适从",
	"force" : 210,
	"dodge" : 25,
	"damage": 40,
	"lvl" : 30,
	"skill_name" : "陈字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N心念「探字诀」，用虚招引开$n的攻击，右手$w急挥，向$n的$l劈去",
	"force" : 240,
	"dodge" : 15,
	"damage": 50,
	"lvl" : 40,
	"skill_name" : "探字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N手捏「逼字诀」，手中$w劈斩砍打，一招接一招不停地向$n的$l猛攻",
	"force" : 280,
	"dodge" : 25,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "逼字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N刀锋暗收，一招「藏字诀」，刀光乍展，指上打下，指东打西，杀机无限",
	"force" : 330,
	"dodge" : 25,
	"damage": 70,
	"lvl" : 60,
	"skill_name" : "藏字诀",
	"damage_type" : "割伤"
]),
([	"action" : "$N意守「错字诀」，步步玄机，招招错乱，$n顿时迷离失措，束手待毙",
	"force" : 380,
	"dodge" : 30,
	"damage": 80,
	"lvl" : 70,
	"skill_name" : "错字诀",
	"damage_type" : "割伤"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="huifeng-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的临济十二庄火候太浅。\n");
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
	level   = (int) me->query_skill("yanxing-dao",1);
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
		return notify_fail("你的精力不够练雁行刀法。\n");
	if (me->query_skill("yanxing-dao", 1) < 100)
		me->receive_damage("jingli", 35);
	else
		me->receive_damage("jingli", 20);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yanxing-dao/" + action;
}

