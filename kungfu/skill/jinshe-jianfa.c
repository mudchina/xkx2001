//Cracked by Roath
// jinshe-jianfa.c 金蛇剑法 
// qfy Nov 22, 1996

inherit SKILL;

mapping *action = ({
([      "action":"$N弓步沉肩，一招「金光蛇影」，手中$w突然刺向$n的$l，随即急速收回",
	"force" : 125,
	"dodge" : -0,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "金光蛇影",
	"damage_type":  "刺伤"
]),
([      "action":"$N使出「蛇影万道」，$w尖颤动抖出一大片剑花，一连串急刺$n的$l",
	"force" : 160,
	"dodge" : -0,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "蛇影万道",
	"damage_type":  "割伤"
]),
([      "action":"$N催动身法急走如飞，使出「雪地飞蛇」，脚步七虚三实，在$n身前身后连续闪动，$w劈向其$l",
	"force" : 200,
	"dodge" : 10,
	"damage": 35,
	"lvl" : 20,
	"skill_name" : "雪地飞蛇",
	"damage_type":  "割伤"
]),
([      "action":"$N迅速诡秘的迈步，一招「金蛇吞信」，$w幻出点点剑光，闪烁不定地点向$n",
	"force" : 250,
	"dodge" : 10,
	"damage": 45,
	"lvl" : 30,
	"skill_name" : "金蛇吞信",
	"damage_type":  "刺伤"
]),
([      "action":"$N中的$w抖起一片剑花，使出「金蛇狂舞」，在空中划了一连串的折线，扫向$n的$l",
	"force" : 300,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 40,
	"skill_name" : "金蛇狂舞",
	"damage_type":  "割伤"
]),
([      "action":"$N仰天长啸，施展「灵蛇电闪」，劲力到处$w弯成弓形，突然一松手，电光一闪劈空刺向$n",
	"force" : 340,
	"dodge" : 5,
	"damage": 65,
	"lvl" : 50,
	"skill_name" : "灵蛇电闪",
	"damage_type":  "刺伤"
]),
([      "action":"$N突然绕着$n迅捷游走，一招「蛇困愁城」将$w挥出，刺在意想不到的位置上，$n正眼花缭乱不知所措，一头撞了上去",
	"force" : 380,
	"dodge" : 10,
	"damage": 75,
	"lvl" : 60,
	"skill_name" : "蛇困愁城",
	"damage_type":  "刺伤"
]),
([      "action":"$N刹住所有花招虚步，高高举起手中$w，功力到处，$w一阵颤动隐隐发出龙吟，一式「金蛇化龙」，霎时金光一道破空而至，向$n当头罩下",
	"force" : 410,
	"dodge" : 5,
	"damage": 85,
	"lvl" : 70,
	"skill_name" : "金蛇化龙",
	"damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("你的内功心法火候太浅，无法学习金蛇剑法。\n");

	if ((int)me->query_int() < 30)
		return notify_fail("你的悟性不够，无法领悟金蛇剑法。\n");

	if ((int)me->query_con() < 20)
		return notify_fail("你的根骨不够，无法练金蛇剑法。\n");

	if (!present("jinshe miji", me)) 
		return notify_fail("练习金蛇剑法必须一面研读《金蛇密籍》。\n");

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
	int i, level1, level2, level3;
	object target, anqi;

	level1 = (int) me->query_skill("jinshe-jianfa",1);
	level2 = (int) me->query_skill("youshen-zhang",1);
	level3 = (int) me->query_skill("jinshe-zhuifa",1);
	target = me->select_opponent();
	weapon = me->query_temp("weapon");

	if ( level1 >= 120 && level2 >= 120 && random(level2) > level2 * 1/2
	&& me->query_skill_mapped("strike") == "youshen-zhang" 
	&& me->query_skill_prepared("strike") == "youshen-zhang" 
	&& me->query("neili") > 10 && me->query("jingli") > 5 ) {
		weapon->unequip();
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		weapon->wield();
		me->add("neili", -10);
		me->add("jingli", -5);
	}

	if ( level1 >= 120 && level3 >= 100 && random(level3) > level3 * 1/2
	&& me->query("neili") > 10 && me->query("jingli") > 5) {
		if ( objectp(anqi=present("jinshe zhui", me)) ) {
			anqi->throw_ob(me, target);
			me->add("neili", -10);
			me->add("jingli", -5);
		}
	}

	for(i = sizeof(action); i > 0; i--)
		if(level1 > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level1/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练金蛇剑法。\n");

	me->receive_damage("jingli", 25, "精力透支过度死了");

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"jinshe-jianfa/" + action;
}
