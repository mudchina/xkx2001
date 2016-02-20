//Cracked by Roath
// shenlong-goufa.c 神龙钩法
// ywz 06/20/1997

inherit SKILL;

mapping *action = ({
([      "action" : "只见$N双钩一上一下，一招「翻天覆地」同时攻向$n的头部与腿部。",
	"force" : 120,
	"dodge" : 20,
	"damage" : 5,
	"lvl" : 0,
//	"damage_type" : "割伤"
]),
([      "action" : "只见$N前钩虚攻$n的上身，后钩却以迅雷不及掩耳之势向$n的腰部钩去。好一招「若离若合」！",
	"force" : 140,
	"dodge" : 15,
	"damage" : 10,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([      "action" : "只见$N一招「雪满银钩」将双钩舞得如同雪花纷飞，将$n的全身拢罩在$N双钩之下。",
	"force" : 160,
	"dodge" : 10,
	"damage" : 15,
	"lvl" : 0,
	"damage_type" : "砍伤"
]),
([      "action" : "只见$N使出「天王索命」，一钩紧似一钩，一钩快似一勾，一气呵成，直逼$n的周身大穴。",
	"force" : 180,
	"dodge" : 5,
	"damage" : 20,
	"lvl" : 9,
	"damage_type" : "砍伤"
]),
([      "action" : "$N一招「天马行空」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"force" : 200,
	"dodge" : 15,
	"damage" : 20,
	"lvl" : 9,
//	"damage_type" : "割伤"
]),
([      "action" : "$N一招「神龙摆尾」，右脚虚上，右手回收，$w向下截劈$n的$l",
	"force" : 220,
	"dodge" : 10,
	"damage" : 25,
	"lvl" : 9,
	"damage_type" : "砍伤"
]),
([      "action" : "$N一招「钩心斗角」，双钩一左一右，一气呵成横扫$n的$l",
	"force" : 190,
	"dodge" : 10,
	"damage" : 25,
	"lvl" : 19,
	"damage_type" : "砍伤"
]),
([      "action" : "$N右脚向前一步，左膝提起，一招「不阴不阳」，$w向前上方刺向$n的$l",
	"force" : 210,
	"dodge" : 15,
	"damage" : 35,
	"lvl" : 19,
	"damage_type" : "刺伤"
]),
([      "action" : "$N使一招「尔虞我诈」，右脚向后回撤，$w随身体右后撤，突然向左前方刺向$n的$l",
	"force" : 230,
	"dodge" : 5,
	"damage" : 20,
	"damage_type" : "刺伤"
]),
([      "action" : "$N使出「峰峦重叠」，$w划出三个圆弧，绵绵不断划向$n的$l",
	"force" : 240,
	"dodge" : 10,
	"damage" : 40,
	"lvl" : 29,
//	"damage_type" : "割伤"
]),
([      "action" : "$N一转身，双钩向后斜带，一招「飞横拔户」，砍向$n的$l",
	"force" : 260,
	"dodge" : 5,
	"damage" : 45,
	"lvl" : 29,
	"damage_type" : "砍伤"
]),
([      "action" : "$N双手握钩，微一低头，一招「闭门思过」，双钩突然从脑后疾向$n刺去",
	"force" : 260,
	"dodge" : 10,
	"damage" : 40,
	"lvl" : 29,
	"damage_type" : "刺伤"
]),
([      "action" : "$N突然把左钩套在右钩上，一招「左短右长」，抹向$n的$l",
	"force" : 280,
	"dodge" : 15,
	"damage" : 45,
	"lvl" : 39,
//	"damage_type" : "割伤"
]),
([      "action" : "$N突然把右钩套在左钩上，一招「右短左长」，抹向$n的$l",
	"force" : 280,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 39,
//	"damage_type" : "割伤"
]),
([      "action" : "$N双手钩头向内，一招「欲擒故纵」，倒转身体，双钩刺向$n",
	"force" : 300,
	"dodge" : 5,
	"damage" : 55,
	"lvl" : 39,
	"damage_type" : "刺伤",
]),
([      "action" : "$N一招「对牛弹琴」，双钩相互碰撞「铮！」，在$n一楞之间突然划向$n的$l",
	"force" : 320,
	"dodge" : 10,
	"damage" : 50,
	"lvl" : 49,
//	"damage_type" : "割伤"
]),
([      "action" : "$N一招「一心两用」，双钩一劈一刺击向$n",
	"force" : 320,
	"dodge" : 5,
	"damage" : 55,
	"lvl" : 49,
	"damage_type" : "刺伤",
]),
([      "action" : "$N双脚并步，身体立起，一招「莲叶托桃」，双钩向前平刺$n的档部",
	"force" : 360,
	"dodge" : 0,
	"damage" : 55,
	"lvl" : 49,
	"damage_type" : "刺伤"
]),
([      "action" : "$N左脚向前进一步，双钩「各行其路」，分别刺向$n的左右胸",
	"force" : 360,
	"dodge" : 5,
	"damage" : 55,
	"lvl" : 59,
	"damage_type" : "刺伤"
]),
([      "action" : "$N一招「群魔乱舞」，双钩舞动护住全身向$n撞去",
	"force" : 360,
	"dodge" : 0,
	"damage" : 65,
	"lvl" : 59,
//	"damage_type" : "割伤"
]),
([      "action" : "$N一反身，使一招「鱼死网破」，双钩不故一切得劈向$n的$l",
	"force" : 380,
	"dodge" : 5,
	"damage" : 70,
	"lvl" : 69,
	"damage_type" : "砍伤"
]),
([      "action" : "$N右脚向前垫步，一招「流星赶月」，左钩突然向$n扔了过去",
	"force" : 380,
	"dodge" : 0,
	"damage" : 75,
	"lvl" : 79,
	"damage_type" : "刺伤"
]),
([      "action" : "$N右手$w向后撤，再向前平平托起，一招「描龙绣凤」刺向$n的$l",
	"force" : 400,
	"dodge" : -5,
	"damage" : 80,
	"lvl" : 79,
	"damage_type" : "刺伤"
]),
([  "action" : "$N一招「殊路同归」，双钩中宫直进，一上一下刺向$n的$l",
	"force" : 420,
	"dodge" : -5,
	"damage" : 85,
	"lvl" : 89,
	"damage_type" : "刺伤"
]),
([      "action" : "$N身子向上纵起，一招「天地同寿」，头下脚上，双钩向$n的头顶刺去",
	"force" : 420,
	"dodge" : -10,
	"damage" : 85,
	"lvl" : 89,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "hook") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("你的毒龙大法火候太浅。\n");
	if ((int)me->query_skill("hook", 1) < 20)
		return notify_fail("你的钩法基本功还不扎实。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level  = (int) me->query_skill("ruyi-gou",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hook")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 40)
		return notify_fail("你的精力不够练神龙钩法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"ruyi-gou/" + action;
}

mapping *query_skilldbase() {return action;}
