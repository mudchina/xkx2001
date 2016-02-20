//Cracked by Roath
// mian-zhang.c 绵掌
// xQin 12/98
// xQin 11/00

#include <combat.h>
inherit SKILL;


nomask int parry_available() { return 1; }

string *parry_msg = ({
	"$p当下展开绵掌，抱元归一，全身要害守得毫无漏洞。\n",
	"$p不闪不让，待$w到面门数寸，突然发招，左掌直切$P右手脉门。\n",
	"$p双掌一错，封紧门户，连连解去$P的随势进攻，稳步倒退。\n",
	"$p变招奇快，左腿「横云断峰」，掠地扫去。\n",
	"$p一惊，退开一步，左掌「拨云见日」，向旁掠出。\n",
	"$p下盘「盘弓射雕」，双手以擒拿法反扣$P脉门。\n",
	"$p发“鸳鸯腿”攻$P左胁，使$N不得不闪避收招。\n",
	"$p退“讼”位，进“无妄”，点“天泉”。\n",
	"$p退“中孚”，以凤眼手化开。\n",
	"$p退“震”位，又退“复”位，再退“未济”。\n",
	"$p当下手腕一翻，使半招「九转丹成」，转了个圈子，登时将$P$w甩落。\n",
	"$p早已凝聚真气，暗运功力，待$P$w攻到，当即伸出右掌，以师门心传的“绵掌”还击。\n",
	"$p左臂稍曲，以一招「横架金梁」挡住。\n",
});

string query_parry_msg(object weapon, object victim) 
{ 
	if( victim->query_temp("weapon") || victim->query_skill("mian-zhang", 1) < 100
		|| victim->query_skill_prepared("strike") != "mian-zhang" )
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return parry_msg[random(sizeof(parry_msg))];
}

mapping *action = ({
([	"action": "忽见$N招数一变，双掌飞舞，有若「絮飘雪扬」，软绵绵不着力气",
	"force" : 160,
	"dodge" : 10,
	"damage": 5,
	"lvl" : 0,
	"skill_name" : "絮飘雪扬",
	"damage_type": "内伤"
]),
([	"action": "$N当下气凝右臂，使一招「自在飞花」，奋力挥掌往$n$l拍去",
	"force" : 200,
	"dodge" : 15,
	"damage": 10,
	"lvl" : 13,
	"skill_name" : "自在飞花",
	"damage_type": "内伤"
]),
([	"action": "$N一招「仙鹤亮翅」，倏地斜穿闪过，回手左掌，向$n$l打到",
	"force" : 260,
	"dodge" : 20,
	"damage": 15,
	"lvl" : 26,
	"skill_name" : "仙鹤亮翅",
	"damage_type": "瘀伤"
]),
([	"action": "$N右手反腕，一招「仙剑斩龙」向$n右掌手背按落，左掌猛击$p$l",
	"force" : 320,
	"dodge" : 0,
	"damage": 25,
	"lvl" : 39,
	"skill_name" : "仙剑斩龙",
	"damage_type": "瘀伤"
]),
([	"action": "$N运力右掌，一招「拱云托月」，手腕翻过，下肘转了个小圈，向$n$l拍去",
	"force" : 245,
	"dodge" : 5,
	"damage": 35,
	"lvl" : 52,
	"skill_name" : "拱云托月",
	"damage_type": "内伤"
]),
([	"action": "$N突然胸口一缩，双臂回环，一招「孤云出岫」，左手食指和右手食指同时击向$n$l",
	"force" : 400,
	"dodge" : 25,
	"damage": 30,
	"lvl" : 65,
	"skill_name" : "孤云出岫",
	"damage_type": "内伤",
]),
([	"action": "$N「白露横江」左掌拍出，右掌陡地里后发先至，跟着左掌斜穿，又从后面抢了上来",
	"force" : 450,
	"dodge" : 30,
	"damage": 40,
	"lvl" : 78,
	"skill_name" : "白露横江",
	"damage_type": "瘀伤"
]),
([	"action": "$N招数忽变，双掌轻飘飘地，若有若无的拍击而出，使招「海底翻花」，左手虚引，右手倏出，向$n$l点来",
	"force" : 370,
	"dodge" : 35,
	"damage": 20,
	"lvl" : 91,
	"skill_name" : "海底翻花",
	"damage_type": "内伤"
])
});

int valid_enable(string usage)
{
	return usage=="strike" ||  usage=="parry";
}

int valid_combine(string combo)
{
	if (this_player()->query_skill("taiji-shengong", 1) > 99)
	return combo=="taiji-quan";
	
}

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练习绵掌必须空手。\n");

	if( (int)me->query_skill("force", 1) < 19)
		return notify_fail("你的内功修为尚浅，不能学习绵掌。\n");

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力太弱，无法练习绵掌。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for( i = sizeof(action)-1; i >= 0; i-- )
		if( level >= action[i]["lvl"] )
			return action[i]["skill_name"];
}



int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的体力不够练绵掌。\n");

	if( (int)me->query("neili") < 20 )
		return notify_fail("你的内力不够练绵掌。\n");

	me->receive_damage("jingli", 25, "体力透支过度死了");
	me->add("neili", -10);
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;

	if( me->query_temp("double_huakai") )
		return ([
			"action": "$N双手递招之后，跟着右掌击$p左颊，左手食指点$p右肩后“缺盆穴”",
			"force" : 500,
			"dodge" : 15,
			"damage": 45,
        		"damage_type" : random(2)?"内伤":"瘀伤"
			]);

	level = (int)me->query_skill("mian-zhang", 1);
	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
	me->delete_temp("double_huakai");
}
	
string perform_action_file(string action)
{
	return __DIR__"mian-zhang/" + action;
}


