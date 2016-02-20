//Cracked by Roath
// fengmo-zhang.c 丐帮疯魔杖法
// qfy November 30, 1997

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action":"$N手执$w大开大阖，左右挥舞，使出「罗刹开路」，打向$n的$l",
        "force" : 150,
        "dodge" : 2,
        "parry" : 2,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "罗刹开路",
        "damage_type":  "挫伤"
]),
([      "action":"$N施出「轮徊无常」手握$w杖尾，以头顶为轴心急速的转动，$w带着呼呼风声撞向n",
        "force" : 200,
        "dodge" : 0,
        "parry" : 5,
        "damage": 30,
        "lvl" : 10,
        "skill_name" : "轮徊无常",
        "damage_type":  "劈伤"
]),
([      "action":"$N一着「秦王鞭石」，双手紧握$w高举过顶，一声大喝，$w威猛无畴地往$n头上砸下",
        "force" : 250,
        "dodge" : 5,
        "parry" : 5,
        "damage": 40,
        "lvl" : 25,
        "skill_name" : "秦王鞭石",
        "damage_type":  "劈伤"
]),
([      "action":"$N将$w举在头顶运转如风，使出「罗汉献佛」把急转着的$w向$n掷出，接着双手合十，身形飘前接过$w",
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "damage": 50,
        "lvl" : 35,
        "skill_name" : "罗汉献佛",
        "damage_type":  "挫伤"
]),
([      "action":"$N飞身跃起，一掌护胸，单手提杖一招「魔影重重」，$w激起狂野杖风，指向$n的$l",
        "force" : 350,
        "dodge" : 10,
        "parry" : 5,
	"damage": 65,
        "lvl" : 45,
        "skill_name" : "魔影重重",
        "damage_type":  "挫伤"
]),
([      "action":"$N迅速的转动$w，在身前左右幻起一片杖屏，猛然地冲近$n施展「罗刹索命」，$w向$n$l奔雷般地劈下",
        "force" : 400,
        "dodge" : 10,
        "parry" : 10,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "罗刹索命",
        "damage_type":  "劈伤"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 20)
                return notify_fail("你的混天气功火候太浅。\n");
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

	level = (int)me->query_skill("fengmo-zhang",1);
	
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
                return notify_fail("你的精力不够练疯魔杖法。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"fengmo-zhang/" + action;
}
