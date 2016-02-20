//Cracked by Roath
// wuhu-gun.c 五虎棍

inherit SKILL;

mapping *action = ({
([      "action" : "$N力透手腕，一招「上滑下劫」，$w上下翻滚，舞成一团光圈击向$n的$l",
        "force" : 180,
      "parry" : 10,
        "damage" : 10,
        "lvl" : 0,
        "skill_name" : "上滑下劫",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N劲贯双臂，使一招「扬眉吐气」，$w势夹劲风，向$n的$l挑去",
        "force" : 260,
      "parry" : 20,
        "damage" : 20,
        "lvl" : 3,
        "skill_name" : "扬眉吐气",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N吸一口气，一招「翻天彻地」，手中$w划出一道大弧，朝$n的$l狠狠砸下",
        "force" : 300,
      "parry" : 10,
        "damage" : 25,
        "lvl" : 8,
        "skill_name" : "翻天彻地",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N舞动手中$w，一招「青龙卷尾」，带着“呜呜”风声，向$n的$l猛扫而至",
        "force" : 330,
      "parry" : 15,
        "damage" : 35,
        "lvl" : 16,
        "skill_name" : "青龙卷尾",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一个转身，卖个破绽，一招「铁牛耕地」，手中$w出其不意的着地卷向$n的$l",
        "force" : 360,
      "parry" : 25,
        "damage" : 35,
        "lvl" : 24,
        "skill_name" : "铁牛耕地",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N舒肩伸臂，使一招「挑袍撩衣」，变招奇速，$w自下向上抄起，攻向$n的$l",
        "force" : 420,
      "parry" : 20,
        "damage" : 40,
        "lvl" : 33,
        "skill_name" : "挑袍撩衣",
        "damage_type" : "瘀伤"
]),
});


int valid_enable(string usage) { return usage == "stick" || usage == "parry" || usage == "club"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
/*
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
                return notify_fail("你的混元一气功火候太浅。\n");
*/
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
        level   = (int) me->query_skill("wuhu-gun",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
//        || (string)weapon->query("skill_type") != "stick"
        || (string)weapon->query("skill_type") != "club")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练五虎棍。\n");
        me->receive_damage("jingli", 25);
        return 1;
}
