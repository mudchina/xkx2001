//Cracked by Roath
// 虎爪绝户手 huzhua-juehu.c

inherit SKILL;

mapping *action = ({
([	"action" : 
"$N双手一分，使出一式「月孛入命」，手腕螺旋翻转，无声无息地拿向$n的$l",
	"force" : 320,
	"dodge" : 20,
	"damage": 35,
	"lvl"   : 0,
	"skill_name" : "月孛入命" ,		
	"damage_type" : "内伤"
]),
([	"action" : 
"$N一声长啸，五指戟张，使出一式「计蒙化血」，爪式中宫直进，刚猛无匹地捣向$n的$l",
	"force" : 360,
	"dodge" : 20,
	"damage": 40,
	"lvl"   : 15,
	"skill_name" : "计蒙化血" ,		
	"damage_type" : "抓伤"
]),
([	"action" : 
"$N双爪开和，动静互易，一式「玄武夜泣」，双手交错绞缠，若夜风轻烟般锁向$n的$l",
	"force" : 400,
	"dodge" : 25,
	"damage": 50,
	"lvl"   : 30,
	"skill_name" : "玄武夜泣" ,		
	"damage_type" : "抓伤"
]),
([	"action" : 
"$N身形起处，双爪盘旋翻飞，一式「朱雀伏尸」，十指过处嗤嗤破风声不绝，迅捷无伦地插向$n的$l",
	"force" : 450,
	"dodge" : 25,
	"damage": 65,
	"lvl"   : 45,
	"skill_name" : "朱雀伏尸" ,		
	"damage_type" : "抓伤"
]),
([	"action" : 
"$N身形飞旋，凌空下击，正是一招「青龙嫉主」，爪式矫夭险狠，如恶龙夺珠抓向$n的$l",
	"force" : 500,
	"dodge" : 30,
	"damage": 85,
	"lvl"   : 60,
	"skill_name" : "青龙嫉主" ,		
	"damage_type" : "抓伤"
]),
([	"action" : 
"$N内息吞吐，招式展动，一招「白虎绝户」，似慢实快，双手微微颤动，夹着一股激厉无前的阴刚之力袭向$n的$l",
	"force" : 560,
	"dodge" : 40,
	"damage": 75,
	"lvl"   : 75,
	"skill_name" : "白虎绝户" ,		
	"damage_type" : "抓伤"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练虎爪绝户手必须空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 100)
		return notify_fail("你的太极神功火候不够，无法学虎爪绝户手。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练虎爪绝户手。\n");
	if ((int)me->query("shen") < (int)me->query_skill("huzhua-juehu",1)*1000)
		return notify_fail("你的侠义正气太低，无法练虎爪绝户手。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("huzhua-juehu",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}


int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练虎爪绝户手。\n");
        if ((int)me->query("shen") <(int)me->query_skill("huzhua-juehu",1)*1000)
                return notify_fail("你的侠义正气太低，练虎爪绝户手会走火入魔。\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -10);
	return 1;
}

