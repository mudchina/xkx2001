//Cracked by Roath
///kungfu/skill/yulong-baibian.c 鱼龙百变
// Snowbird July 1999
// 1.1.1.1

inherit SKILL;

mapping *action = ({
([      "action" : "$n一式「金鲤跃波」轻巧跃起，再半空回旋一周，轻飘飘地落到$N身后。\n",
        "dodge"  : 10,
        "skill_name" : "金鲤跃波"
]),
([      "action" : "$n眼见敌招将至，身形一转，便是一招「鱼翔潜底」，刹那间隐得无影无踪。\n",
        "dodge"  : 20,
        "skill_name" : "鱼翔潜底"
]),
([      "action" : "$n傲然一笑，一式「万鲤争渡」，瞬时间幻出千百个身影，齐向$N攻去，$N大惊失色，所发招式尽数落空。\n",
        "dodge"  : 30,
        "skill_name" : "万鲤争渡"
]),
([      "action" : "$n眼见避无可避，蓦然纵身而起，一式「鲤跃龙门」，身形仿如化做长龙，从$N头顶飘然跃过。\n",
        "dodge"  : 40,
        "skill_name" : "鲤跃龙门"
]),
([      "action" : "$n长啸一声，一招「鸾翔龙腾」腾空而起，在$N头顶周匝数圈，将$N的凌厉攻势化解得无影无踪。\n",
        "dodge"  : 50,
        "skill_name" : "鸾翔龙腾"
]),
([      "action" : "$n双脚一蹬，背脊一挺，随着$N的攻势如飞龙般向后掠去，正是一招「九天飞龙」，$N招式使老，无功而返。\n",
        "dodge"  : 60,
        "skill_name" : "九天飞龙"
]),
([      "action" : "$n气凝丹田，使出「龙腾四海」，如蛟龙腾空般拔地而起，在空中数个转折，轻灵落下。\n",
        "dodge"  : 70,
        "skill_name" : "龙腾四海"
]),
([      "action" : "$n身形急转，便是一招「神龙百变」，身形如龙隐云中，变幻莫测，$N目瞪可呆，攻势不由一滞。\n",
        "dodge"  : 80,
        "skill_name" : "神龙百变"
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("yulong-baibian");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
                  return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练鱼龙百变。\n");
        me->receive_damage("jingli", 30);
        return 1;
}
