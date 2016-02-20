//Cracked by Roath
// yingxiong-sanzhao.c 英雄三招

inherit SKILL;

mapping *action = ({
([      "action" : "$n抓住$N的后颈，一把提起。$N左手慢慢反转，在$n左腋底搔了一把，\n"
		   "$n身子软了下来，$N左手拿住$n腋下，右手慢慢回转，抓住$n领口，缓缓\n"
		   "举起$n的身子，过了自己头顶，向外摔出",
	"force" : 50,
	"dodge" : 5,
	"parry" : 10,
	"damage": 60,
	"lvl" : 0,
	"skill_name" : "子胥举鼎",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N俯伏地上，$n伸右足踏住$N的后腰，$N双腿一缩，似欲跪拜，\n"
		   "右臂却慢慢横掠而出，突然间一个筋斗，向$n的胯下钻去，只一作势\n"
		   "左手已抓住$n右脚足踝，右手向$n小腹击去",
	"force" : 60,
	"dodge" : 20,
	"parry" : 20,
	"damage": 90,
	"lvl" : 10,
	"skill_name" : "鲁达拔柳",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N双臂反在背后，突然双手十指弯起，各成半球之形，身子向后一撞\n"
		   "十指便抓向$n的胸部，$n向后一缩，$N突然一个倒翻筋斗，身子跃起\n"
		   "双腿一分，已跨在$n肩头，同时双手按指压住$n太阳穴，食指按眉，中指按眼",
	"force" : 100,
	"dodge" : 30,
        "parry" : 30,
	"damage": 110,
	"lvl" : 20,
	"skill_name" : "狄青降龙",
	"damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

   int valid_combine(string combo) { return combo=="jueming-tui" ; }

int valid_learn(object me)
{
	if (me->query_int() < 25)
		return notify_fail("你的悟性不够，无法学英雄三招。\n");
        if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法学英雄三招。\n");
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
	level   = (int) me->query_skill("yingxiong-sanzhao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练英雄三招。\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

/*
string perform_action_file(string action)
{
	return __DIR__"yingxiong-sanzhao/" + action;
}
*/
