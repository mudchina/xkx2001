//Cracked by Roath
// yingzhua-qinna.c -鹰爪擒拿手

inherit SKILL;

mapping *action = ({
([      "action" : "$N倏地抢上一步，左臂横挥，一转身，双手十指犹似两把鹰爪，猛插$n的$l",
        "force" : 120,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 0,
        "damage_type" : "抓伤"
]),
([      "action" : "$N丹田真气鼓荡，掌心之中内力如潮，有如一个浪头又是一个浪头般连绵不绝，从双掌上向$n撞击过去",
        "force" : 160,
        "dodge" : 10,
        "parry" : 10,
        "damage": 5,
        "lvl" : 15,
        "damage_type" : "内伤"
]),
([      "action" : "$N招数呆滞，东出一掌，西打一拳，当真不成章法，但却是大智若愚，大巧若拙，实已臻武学中的极高境界",
        "force" : 230,
        "dodge" : 0,
        "parry" : 0,
        "damage": 20,
        "lvl" : 30,
        "damage_type" : "内伤"
]),
([      "action" : "$N出手大开大阖，走的全是刚猛路子，陡然大吼一声，双拳“丁甲开山”，排山倒海般向$n重击",
        "force" : 280,
        "dodge" : 15,
        "parry" : 15,
        "damage": 15,
        "lvl" : 45,
        "damage_type" : "内伤"
]),
([      "action" : "$N身形转动，双掌打得快极，掌风呼呼，威力远及数丈，朝$n正面连连逼迫",
        "force" : 340,
        "dodge" : 10,
        "parry" : 0,
        "damage": 15,
        "lvl" : 60,
        "damage_type" : "内伤"
]),
([      "action" : "$N凝神提气，一掌掌朝$n拍至，忽而跨前，忽而倒退，每踏出一步，脚底便是一个足印，头上白雾升起，内力实已发挥到了极致",
        "force" : 400,
        "dodge" : 0,
        "parry" : 0,
        "damage": 0,
        "lvl" : 75,
        "damage_type" : "内伤"
]),
([      "action" : "$N神威凛凛，双目炯炯，如电闪动，蓦地霹雳般一声大喝，以破山碎碑的雄浑掌力，不绝向$n抵压过去",
        "force" : 450,
        "dodge" : 10,
        "parry" : 10,
        "damage": 10,
        "lvl" : 90,
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练鹰爪擒拿手必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练鹰爪擒拿手。\n");
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
        level   = (int) me->query_skill("yingzhua-qinna",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练鹰爪擒拿手。\n");
                
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

