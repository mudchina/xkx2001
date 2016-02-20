//Cracked by Roath
// jingang-chu.c, 金刚降魔杵
// qfy, chage, paoshou Sept 27, 1996

inherit SKILL;

mapping *action = ({
([	"action": "$N神色庄严，口宣佛号，使出一招「金刚再世」，手中$w扫向$n的$l",
	"force" : 150,
	"dodge":  -5,
	"damage": 20,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "挫伤",
	"lvl" : 0,
	"skill_name" : "金刚再世",
]),
([	"action": "$N满面怒容，口中大喝，大步踏上一式「金刚伏魔」，$w朝着$n当头砸下",
	"force" : 200,
	"dodge": -5,
	"damage": 30,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "劈伤",
	"lvl" : 10,
	"skill_name" : "金刚伏魔",
]),
([	"action": "$N一招「金刚宣法」，口中念念有词，骤然眼放异光，抡起手中$w横扫$n的$l",
	"force" : 260,
	"dodge": -10,
	"damage": 40,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "挫伤",
	"lvl" : 20,
	"skill_name" : "金刚宣法",
]),
([      "action": "$N一招「引趣众生」，左臂弯夹$w，右展立，呼心金咒，单臂挥$w击向$n的$l",
        "force" : 320,
        "dodge": -10,
        "damage": 40,
        "damage_type": "劈伤",
        "lvl" : 30,
        "skill_name" : "引趣众生",
]),
([      "action": "$N一式「歌舞阎罗」，口唱轮回经，跨腿飞跳，$w首尾来回击向$n",
        "force" : 380,
        "dodge": -10,
        "damage": 40,
        "damage_type": "挫伤",
        "lvl" : 40,
        "skill_name" : "歌舞阎罗",
]),
([	"action": "忽然间$N一脸悲珉之色，手中$w画个半弧使出「浮游血海」，勾向$n的$l",
	"force" : 410,
	"dodge": -10,
	"damage": 45,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"damage_type": "挫伤",
	"lvl" : 50,
	"skill_name" : "浮游血海",
]),
([      "action": "$N一式「驱鬼御魔」，口中念着六字真言，把$w舞成一片黄雾，将$n罩在中央",
        "force" : 440,
        "dodge": -10,
        "damage": 70,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 60,
        "skill_name" : "驱鬼御魔",
]),
([      "action": "$N闭目运气鼓足内力，暴喝一声佛号施展「荡魔除妖」，手中$w飞云掣电般直射向$n的$l",
        "force" : 470,
        "dodge": -10,
        "damage": 75,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type": "挫伤",
        "lvl" : 70,
        "skill_name" : "荡魔除妖",
])
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20
	&& (int)me->query_skill("xiaowuxiang", 1) < 20){
		return notify_fail("你的内功修为火候太浅。\n");
	}
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
	level   = (int) me->query_skill("jingang-chu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
	if (me->query_str() < 20)
                return notify_fail("你的臂力不够练金刚降魔杵。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练金刚降魔杵。\n");
	me->receive_damage("jingli", 20);
        if(me->query_skill("jingang-chu", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("jingang-chu", 1) > 150)
        me->receive_damage("jingli", 5);
	return 1;
}
