//Cracked by Roath
// taiji-quan.c 太极拳
// fang 6/26/96
// Ryu 12/12/97
// by aln 4/98
// xQin 6/2000

inherit SKILL;

nomask int parry_available() { return 1; }

string *parry_msg = ({
	"$p眼见$P$w攻到，当即使出一招「揽雀尾」，右脚实，左脚虚，运起“挤”字诀，粘连粘随，右掌已搭住$P左腕，横劲发出。$N身不由主的向前一冲，跨出两步，方始站定。\n",
	"不料$p双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡，只带得$P在原地急转七八下。\n",
	"$p「双风贯耳」，连消带打，双手成圆形击出，随即左圈右圈，一个圆圈跟着一个圆圈，大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出，登时便套得$P跌跌撞撞，身不由主的立足不稳。\n",
	"$p使出一招「云手」，左手高，右手低，一个圆圈已将$P$w套住。\n",
	"$p觉气息微窒，当下一招「斜飞势」，将$P$w引偏。\n",
	"$p吸一口气，体内真气流转，右掌挥出，一拒一迎，将$P的力道尽行碰了回去。\n",
	"$p双掌一翻，使出一招「云手」，双掌柔到了极处，空明若虚，将$P$w的急劲尽数化去。\n",
	"$p当即双掌一扬，迎着$w接去，待得手掌与$P$w将触未触之际，施出「揽雀尾式」，将$w轻轻拢住，脚下“金鸡独立式”，左足关地，右足悬空，全身急转，宛似一枚陀螺。\n",
	"就在这电光石火的一瞬之间，$p身子一弓，正是「白鹤亮翅」的前半招，$P的劲力登时落空。\n",
});

string query_parry_msg(object weapon, object victim) 
{
	if ( victim->query_temp("weapon") || victim->query_skill("taiji-quan", 1) < 100
	|| victim->query_skill_prepared("cuff") != "taiji-quan" )
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return parry_msg[random(sizeof(parry_msg))];
}

mapping *action = ({
([	"action" : "$N使一招「揽雀尾」，双手划了个半圈，按向$n的$l",
	"force" : 120,
	"dodge" : 30,
	"lvl" : 0,
	"skill_name" : "揽雀尾",
	"damage_type" : "内伤"
]),
([	"action" : "$N右手拉带，左手一招「单鞭」抡向$n的头部",
	"force" : 140,
	"dodge" : 25,
	"lvl" : 5,
	"skill_name" : "单鞭",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手合力抓住$n的手臂，使一招「提手上式」，往上抛出",
	"force" : 160,
	"dodge" : 20,
	"lvl" : 10,
	"skill_name" : "提手上式",
	"damage_type" : "跌伤"
]),
([	"action" : "$N威风凛凛地使一招「白鹤亮翅」，左手下按，右手往上向$n的$l打去",
	"force" : 220,
	"dodge" : 15,
	"lvl" : 15,
	"skill_name" : "白鹤亮翅",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一个弓步向前，使一招「搂膝拗步」，左手搂住$n，右手击向$n的$l",
	"force" : 270,
	"dodge" : 10,
	"lvl" : 20,
	"skill_name" : "搂膝拗步",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手上下挥动，一招「手挥琵琶」，猛击$n的$l",
	"force" : 280,
	"dodge" : 30,
	"lvl" : 25,
	"skill_name" : "手挥琵琶",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手划弧，右手突然从左肘下击出，一记「肘底看锤」猛击$n的$l",
	"force" : 300,
	"dodge" : 25,
	"lvl" : 30,
	"skill_name" : "肘底看锤",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手抓住$n，右手一招「海底针」，向下猛刺$n的裆部",
	"force" : 320,
	"dodge" : 20,
	"lvl" : 35,
	"skill_name" : "海底针",
	"damage_type" : "抓伤"
]),
([	"action" : "$N一个「闪通背」，一侧身用左肘击向$n的胸部",
	"force" : 330,
	"dodge" : 15,
	"lvl" : 40,
	"skill_name" : "闪通背",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一侧身，使一招「斜飞式」，用右肩靠向$n的胸部",
	"force" : 330,
	"dodge" : 15,
	"lvl" : 45,
	"skill_name" : "斜飞式",
	"damage_type" : "跌伤"
]),
([	"action" : "$N左手虚按，右手使一招「白蛇吐信」，向$n的$l插去",
	"force" : 330,
	"dodge" : 30,
	"lvl" : 50,
	"skill_name" : "白蛇吐信",
	"damage_type" : "抓伤"
]),
([	"action" : "$N双手握拳，向前向后划弧，一招「双峰贯耳」打向$n的$l",
	"force" : 340,
	"dodge" : 25,
	"lvl" : 55,
	"skill_name" : "双峰贯耳",
	"damage_type" : "内伤"
]),
([	"action" : "$N左手虚划，右手一记「指裆锤」击向$n的裆部",
	"force" : 340,
	"dodge" : 20,
	"lvl" : 60,
	"skill_name" : "指裆锤",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使出「伏虎式」，右手击向$n的$l，左手攻向$n的裆部",
	"force" : 350,
	"dodge" : 15,
	"lvl" : 65,
	"skill_name" : "伏虎式",
	"damage_type" : "内伤"
]),
([	"action" : "$N双手不停地划圈，一招「云手」，罩住了$n的全身",
	"force" : 350,
	"dodge" : 10,
	"lvl" : 70,
	"skill_name" : "云手",
	"damage_type" : "内伤"
]),
([	"action" : "$N右脚「金鸡独立」，左膝顶向$n的裆部，右手插向$n的咽喉",
	"force" : 380,
	"dodge" : 10,
	"lvl" : 75,
	"skill_name" : "金鸡独立",
	"damage_type" : "抓伤"
]),
([	"action" : "$N向前微一躬身，一招「高探马」，左手往下一按，右掌猛地插向$n的咽喉",
	"force" : 390,
	"dodge" : 15,
	"lvl" : 80,
	"skill_name" : "高探马",
	"damage_type" : "抓伤"
]),
([	"action" : "$N双手来回翻转，一招「玉女穿梭」，向$n的胸部和腹部同时按去",
	"force" : 400,
	"dodge" : 25,
	"lvl" : 85,
	"skill_name" : "玉女穿梭",
	"damage_type" : "内伤"
]),
([	"action" : "$N一个「反身撇锤」，右拳划大弧圈抡向$n的面部",
	"force" : 400,
	"dodge" : 20,
	"lvl" : 90,
	"skill_name" : "反身撇锤",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一个「转身蹬腿」，左脚向$n的腰部蹬去",
	"force" : 400,
	"dodge" : 30,
	"lvl" : 95,
	"skill_name" : "转身蹬腿",
	"damage_type" : "跌伤"
]),
([	"action" : "$N使一招「搬拦锤」，左手一搬一拦，右手一拳打向$n的$l",
	"force" : 400,
	"dodge" : 30,
	"lvl" : 100,
	"skill_name" : "搬拦锤",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N向前迈出左弓步，右手一记「栽锤」，一拳击向$n的头部",
	"force" : 400,
	"dodge" : 25,
	"lvl" : 105,
	"skill_name" : "栽锤",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「野马分鬃」，双手擒住$n的手臂，肩部猛地向$n的胁下靠去",
	"force" : 400,
	"dodge" : 20,
	"lvl" : 110,
	"skill_name" : "野马分鬃",
	"damage_type" : "跌伤"
]),
([	"action" : "$N使一招「抱虎归山」，右手抱住$n的腰，左手拍向$n的脸部",
	"force" : 420,
	"dodge" : 15,
	"lvl" : 115,
	"skill_name" : "抱虎归山",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一个「十字手」，两手从下向上向$n的两胁拍去",
	"force" : 420,
	"dodge" : 10,
	"lvl" : 120,
	"skill_name" : "十字手",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N摆一个左虚步，双手握拳交叉，一个「进步七星」，同时击向$n的喉咙",
	"force" : 430,
	"dodge" : 15,
	"lvl" : 125,
	"skill_name" : "进步七星",
	"damage_type" : "抓伤"
]),
([	"action" : "$N使一招「倒撵猴」，扛起$n，向后摔去",
	"force" : 440,
	"dodge" : 30,
	"lvl" : 130,
	"skill_name" : "倒撵猴",
	"damage_type" : "跌伤"
]),
([	"action" : "只听“啪”的一声，$N使一招「转身摆莲」，右脚踢向$n的背部，两手同时拍向$n的胸腹",
	"force" : 450,
	"dodge" : 20,
	"lvl" : 135,
	"skill_name" : "转身摆莲",
	"damage_type" : random(2)?"瘀伤":"内伤"
]),
([	"action" : "$N左右开弓，一招「弯弓射虎」，右手拽住$n的手臂，左手一拳打向$n的腋下",
	"force" : 460,
	"dodge" : 25,
	"lvl" : 140,
	"skill_name" : "弯弓射虎",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双手划出一个弧圈右一个弧圈，一圈圈把$n团团包围住，仿佛有无数的手掌，一齐拍向$n的全身所有要害。这一招「如封似闭」，十发九中，厉害无比",
	"force" : 500,
	"dodge" : 40,
	"lvl" : 145,
	"skill_name" : "如封似闭",
	"damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太极拳必须空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功火候不够，无法学太极拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练太极拳。\n");
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
	object ob, victim;

	level = (int)me->query_skill("taiji-quan", 1);

	ob = me->select_opponent();

	if( me->query_temp("taiji") )
		me->add_temp("taiji_fight", 1);

	if( me->query_temp("double_attack") == 1 )
	{
		return ([
		"action": "$N左手剑在空中划成大圈，右手剑诀戳出，竟似也发出嗤嗤微声",
		"force" : 380+random(120),
		"dodge" : 20,
		"parry" : 10,
		"damage": 120+random(80),
		"weapon": "右手剑诀",
		"damage_type" : "刺伤" ]);
	}

	if( objectp(victim = me->query_temp("nian")) ) 
	{
		if( ob == victim && !me->query("jiali") && me->query("jiajin") < 2 )
		{
			ob->receive_damage("jing", level/3, "精力透支过度死了");
			ob->receive_damage("jingli", level/3, "精力透支过度死了");
		} 
		else if( !me->query_temp("taiji") &&
		(me->query("jiali") > 0 || me->query("jiajin") > 1) )
		{
			tell_object(me, "\n你加了力后发觉拳行滞缓，双手圆转顿时中断。\n");
			me->delete_temp("nian");
		}
	}

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练太极拳。\n");
	me->receive_damage("jingli", 15);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

int valid_combine(string combo)
{
	if (this_player()->query_skill("taiji-shengong", 1) > 99)
	return combo=="mian-zhang";
}
mapping *query_skilldbase() {return action;}