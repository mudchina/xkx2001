//Cracked by Roath
// chang-quan.c 武当长拳
// xQin 12/98

inherit SKILL;

mapping *action = ({
([	"action": "$N左手一扬，右掌抵在掌心，使招「请手式」挥击出去",
	"force" : 80,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "请手式",
	"damage_type": "瘀伤"
]),
([	"action": "$N左拳一个「冲天炮」，猛向$n击去",
	"force" : 100,
	"dodge" : -5,
	"lvl" : 10,
	"skill_name" : "冲天炮",
	"damage_type": "瘀伤"
]),
([	"action": "$N一个连枝交叉步，双拳「拗鞭」，向$n$l打去",
	"force" : 135,
	"dodge" : -10,
	"lvl" : 20,
	"skill_name" : "拗鞭",
	"damage_type": "瘀伤"
]),
([	"action": "$N手掌向后挥出，应以一招「一条鞭」猛击$n$l，掌势奇妙",
	"force" : 120,
	"dodge" : 15,
	"lvl" : 30,
	"skill_name" : "一条鞭",
	"damage_type": "瘀伤"
]),
([	"action": "$N左足踏进一步，气凝右臂，使出一招「倒骑龙」，挥掌奋力往$n$l拍去",
	"force" : 150,
	"dodge" : 10,
	"lvl" : 40,
	"skill_name" : "倒骑龙",
	"damage_type": "瘀伤"
]),
([	"action": "$N疾纵向前，身随掌起，一招「七星手」，发掌向$n打去",
	"force" : 180,
	"dodge" : 30,
	"lvl" : 50,
	"skill_name" : "七星手",
	"damage_type": "瘀伤"
]),
([	"action": "$N双手一分，使出「高平四」的势子，气劲力足，侧身向$n一拳挥去",
	"force" : 250,
	"dodge" : 15,
	"lvl" : 60,
	"skill_name" : "印掌",
	"damage_type": "瘀伤"
]),
([	"action": "$N身形一矮，一个「印掌」，掌风飒然，已沾$n$l。这一掌蕴劲回力，去势缓慢",
	"force" : 300,
	"dodge" : 0,
	"lvl" : 70,
	"skill_name" : "高平四",
	"damage_type": "内伤"
]),
([	"action": "$N突伸左手，向$n$l拍去，右掌翻处，已搁到$p腋下，一个「懒扎衣」，向$p推去",
	"force" : 333,
	"dodge" : 5,
	"lvl" : 80,
	"skill_name" : "懒扎衣",
	"damage_type": "跌伤"
]),
([	"action": "$N使招「雁翅式」，飞起右脚，一招鸳鸯连环腿，左足跟着踢出，直向$n$l踢去",
	"force" : 300,
	"dodge" : 40,
	"lvl" : 90,
	"skill_name" : "雁翅式",
	"damage_type": "瘀伤"
]),
([	"action": "$N一个“虎纵步”，闪开正面，踏上一步，已到了$n右肩之侧，右掌一招「划手」，向$p$l击去",
	"force" : 350,
	"dodge" : 35,
	"lvl" : 100,
	"skill_name" : "划手",
	"damage_type": "瘀伤"
]),
([	"action": "$N双臂内环，顺手使出一招「井栏」。$n觉劲力如波涛汹涌而来",
	"force" : 500,
	"dodge" : 20,
	"lvl" : 110,
	"skill_name" : "井栏",
	"damage_type": "内伤"
])
});

int valid_enable(string usage)
{
	return usage=="cuff" || usage=="parry";
}

int valid_combine(string combo)
{
	return combo=="mian-zhang";
}

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练习武当长拳必须空手。\n");

	if( !me->query_skill("taiji-gong", 1) && me->query_skill("chang-quan", 1)
		> me->query_skill("wudang-jiuyang", 1) + me->query_con() )
		return notify_fail("你的武当九阳功火候不够，无法学习武当长拳。\n");

	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力修为太弱，无法练习武当长拳。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for( i = sizeof(action)-1; i >= 0; i-- )
		if( level >= action[i]["lvl"] )
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, force;
	object target;

	i = random(sizeof(action));
	level = (int)me->query_skill("chang-quan", 1);
	force = (int)me->query_temp("hit_by");
	target = me->select_opponent();

	if( random(level) >= 180 && force )
	{
		message_vision("\n$N在$n的劲上再加自身劲力反激回去。", me, target);
		me->set_temp("hit_by", 0);
		return ([
			"action": action[i]["action"],
			"force" : action[i]["force"]+force,
			"dodge" : action[i]["dodge"],
			"damage_type": action[i]["damage_type"]
			]);
	}

	if( random(level) >= 110 && force )
	{
		message_vision("\n$N将$n发来的劲力反激回去。", me, target);
		me->set_temp("hit_by", 0);
		return ([
			"action": action[i]["action"],
			"force" : force,
			"dodge" : action[i]["dodge"],
			"damage_type": action[i]["damage_type"]
			]);
	}

	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的体力不够练习武当长拳。\n");

	if( (int)me->query("neili") < 20 )
		return notify_fail("你的内力不够练习武当长拳。\n");

	me->receive_damage("jingli", 15, "体力透支过度死了");
	me->add("neili", -5);

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wudang-unarmed/" + action;
}
