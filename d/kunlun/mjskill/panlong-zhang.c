//Cracked by Roath
// panlong-zhang.c 盘龙杖法
// by Long
// 蛟龙出水 $N身子向前一扑，$w突然从身下激射而出，由下往上击向$n的$1
// 乌龙摆尾 $N挥动手中的$w向$n迎面砸下，$n正要躲闪，$N突然双手一挑，$w尾向$n的$1砸去。
// 逆龙闹海
// 狂龙低头
// 双龙戏珠	$N一抖手中的$w， $w化成两道黑影向$n的$1扑了过去
// 群龙狂舞

inherit SKILL;

mapping *action = ({
([	"action": "$N使出一招「冰河开冻」，手中$w大开大阖扫向$n的$l",
	"force" : 180,
	"dodge":  -5,
	"damage": 30,
	"damage_type": "挫伤",
	"lvl" : 0,
	"skill_name" : "冰河开冻",
]),
([      "action": "$N手中$w飞舞，一招「山洪涌洌」势不可挡地攻向$n的$l",
        "force" : 200,
        "dodge": -5,
        "damage": 40,
        "damage_type": "挫伤",
        "lvl" : 10,
        "skill_name" : "山洪涌洌",
]),
([	"action": "$N手中$w阵阵风响，一招「山风凛冽」向$n的$l攻去",
	"force" : 250,
	"dodge": -5,
	"damage": 45,
	"damage_type": "挫伤",
	"lvl" : 20,
	"skill_name" : "山风凛冽",
]),
([      "action": "$N手中$w斜摆，划出一道道圆弧，一式「冰天雪地」把$n的身影团团罩住",
        "force" : 300,
        "dodge": -5,
        "damage": 55,
        "damage_type": "劈伤",
        "lvl" : 30,
        "skill_name" : "冰天雪地",
]),
([	"action": "$N一招「峰回路转」，$w左右迂回向$n的$l点去",
	"force" : 350,
	"dodge": -10,
	"damage": 60,
	"damage_type": "挫伤",
	"lvl" : 40,
	"skill_name" : "峰回路转",
]),
([      "action": "$N手中$w向外一揽，一式「鹰拿群鹭」，$w首尾截住$n退路，一收$w，击往$n的破绽",
        "force" : 400,
        "dodge": -5,
        "damage": 70,
        "damage_type": "挫伤",
        "lvl" : 50,
        "skill_name" : "鹰拿群路",
]),
([	"action": "$N将身一纵，跃在半空，$w高举过顶，大喝一声，使一招「天山雪崩」，手中$w幻出数十条杖影，将$n上盘要害尽数罩住",
	"force" : 450,
	"dodge": -15,
	"damage": 80,
	"damage_type": "劈伤",
	"lvl" : 60,
	"skill_name" : "天山雪崩",
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 80)
		return notify_fail("你的内力不够。\n");
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
	level   = (int) me->query_skill("tianshan-zhang",1);
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
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练天山杖法。\n");
	me->receive_damage("jingli", 25);
	return 1;
}

