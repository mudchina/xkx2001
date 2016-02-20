//Cracked by Roath
// qingfu-shenfa.c -青蝠身法
// Zhangchi 3/2000

inherit SKILL;

string *dodge_msg = ({
        "只见$n一招「梦蝠攀枝」，腾空而起身体倒挂，躲过了$N这一招。\n",
        "$n双手向两旁一伸，往前一拂，一招「迷蝠展翼」，身子向後飘出躲过了$N的攻击。\n",
        "$n两掌轻轻向下一拍，一个「醉蝠腾空」身体忽左忽右地向上飘起，$N不知攻向何方只好收回招势。\n",
        "$n不退反进，一招「幻蝠无影」绕过$N的攻势，飘到$N的身後。\n",
        "$n诡秘一笑，一式「夜蝠盘空」，身子向后弹射而出，恰好避过$N的进击。\n",
	"$n身子忽如蝙蝠般向左扑出，空中一个回旋，已然在$N身边绕了一圈。这一招直是匪夷所思。\n",
	"$n似乎有意炫耀功夫，竟不远走，便绕着$N急兜圈子。$N使连数招，却始终打不到你的身上。\n",
	"$n踢得黄沙飞扬，一路滚滚，声势威猛，宛如一条数十丈的大黄龙，登时将$n的身影遮住了。\n",
	"$n一闪即至，欺向他的背后，身形如一只大蝙蝠般飘浮不定。\n",
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
                return notify_fail("你的精力太差了，不能练青蝠身法。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

/*
string perform_action_file(string action)
{
        return __DIR__"qingfu-shenfa/" + action;
}

*/