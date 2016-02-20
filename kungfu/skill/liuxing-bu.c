//Cracked by Roath
// liuxingbu 流星步

inherit SKILL;

string *dodge_msg = ({
        "只见$n一式「银鞍照白马」，借力转力身子腾空而起，躲过了$N这一招。\n",
	  "$n身子斜飞而起，一式「飒沓如流星」避过了$N这一招。\n",
	  "$n一式「千里不留行」避过$N的攻势，脚在$N的身上一点，飘出数丈。\n",
	  "$n一转身，双掌往後拍出，借力一招「事了拂衣去」躲开$N这一招。\n", 
	  "$n身子往地下一躺，脚一撑一招「深藏身与名」身子贴地滑出躲开$N的这一招。\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if ((int)me->query_skill("liuxing-bu", 1) >= 30)
		return notify_fail("你的流星步已经无法再用练来提高了。\n");
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练流星步。\n");
        me->receive_damage("jingli", 30);
        return 1;
}
