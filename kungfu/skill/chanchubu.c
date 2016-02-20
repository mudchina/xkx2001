//Cracked by Roath
//蟾蜍步法
//Jay 10/7/96

inherit SKILL;

string *dodge_msg = ({
	"$n「呱」地一声，一式「蟾蜍扑虫」，一下蹦到一边，避开了$N的锋芒。\n",
	"$n使出「蟾飞九天」，双足点地从$N头上一翻而过。\n",
	"$n一招「蛙入稻田」从$N的腋下穿到$P身後。\n",
	"$n「呱呱呱」连叫三声，用「蛙鸣震天」扰乱$N的心神，躲过$N的攻击。\n",
	"$n身子向后一躺，一式「蟾翻白肚」躲过$N这一招。\n",
	"$n向上一纵，使出「金蟾归月」跃起数尺，飘然落到一旁。\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练蟾蜍步法。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

