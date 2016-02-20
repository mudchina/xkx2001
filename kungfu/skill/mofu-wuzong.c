//Cracked by Roath
// mofu-wuzong.c -魔蝠无踪
// Zhangchi 3/2000

inherit SKILL;

string *dodge_msg = ({
        "只见$n一招「梦蝠攀枝」，腾空而起身体倒挂，躲过了$N这一招。\n",
        "$n双手向两旁一伸，往前一拂，一招「迷蝠展翼」，身子向後飘出躲过了$N的攻击。\n",
        "$n两掌轻轻向下一拍，一个「醉蝠腾空」身体忽左忽右地向上飘起，$N不知攻向何方只好收回招势。\n",
        "$n不退反进，一招「幻蝠无影」绕过$N的攻势，飘到$N的身後。\n",
        "$n诡秘一笑，一式「夜蝠盘空」，身子向后弹射而出，恰好避过$N的进击。\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge"); 
}

int valid_learn(object me) 
{ 
	return 1; 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练魔蝠无踪。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

/* add a perform later

string perform_action_file(string action)
{
        return __DIR__"mofu-wuzong/" + action;
}

*/