//Cracked by Roath
// shenghuo-ling.c 圣火令

inherit SKILL;

mapping *action = ({
([      "action": "$N使出圣火令法，手中$w大开大阖扫向$n的$l",
        "force" : 180,
        "dodge":  -5,
        "damage": 30,
        "damage_type": "挫伤",
        "lvl" : 0,
        "skill_name" : "圣火令",
]),
	// add more actions
});

// 武功类型：适合任何兵器。
int valid_enable(string usage) { return (usage == "dodge") || (usage == "parry")
					|| (usage == "blade") || (usage == "sword")
					|| (usage == "staff") || (usage == "stick")
					|| (usage == "hammer") || (usage == "club"); }   // more?

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
        level   = (int) me->query_skill("shenghuo-ling",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你没有武器。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练圣火令。\n");
        me->receive_damage("jingli", 25);
        return 1;
}

