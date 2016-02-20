//Cracked by Roath
// lingshe-shenfa.c 灵蛇身法
// ywz Oct 28, 1996

inherit SKILL;

mapping *action = ({
([      "action" : "$n身形前倾，向前滑行数尺，一式「灵蛇出洞」顿时避开了$N的凌厉攻势。\n",
        "dodge"  : 10
]),
([      "action" : "$n微一低头，身形向旁掠过，轻巧地一式「风行草堰」，化解了$N的攻势。\n",
        "dodge"  : 20
]),
([      "action" : "$n一式「金蛇吐信」，身形蓦然竖立，纵起在$N的头顶。\n",
        "dodge"  : 30
]),
([      "action" : "$n低头恭身，一式「灵蛇摆尾」，身子向旁一扭，将$N的攻势化于无形。\n",
        "dodge"  : 40
]),
([      "action" : "$n使出「金龙横空」，身形左右急速晃动，幻出数个身影，从容地破解$N的攻势。\n",
        "dodge"  : 50
]),
([      "action" : "$n一招「灵蛇归巢」，腾空而起，潇潇洒洒地落到一旁。\n",
        "dodge"  : 60
]),
([      "action" : "$n含笑飘身使出「灵蛇蜕皮」，身形突然一抖，轻飘飘地从$N的腋下穿过。\n",
        "dodge"  : 70
]),
([      "action" : "$n身子徒然一晃，一招「群蛇起舞」，化为无数长龙绕着$N急转，使其无从下手。\n",
        "dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
	level   = (int) me->query_skill("lingshe-shenfa");

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
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*

        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
*/
        return action[random(sizeof(action))]["action"];

}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的精力太差了，不能练灵蛇身法。\n");
	me->receive_damage("jingli", 20);
        return 1;
}
