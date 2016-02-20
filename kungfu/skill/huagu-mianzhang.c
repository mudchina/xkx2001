//Cracked by Roath
// huagu-mianzhang.c
// modified by aln 4 / 98

#include <ansi.h>

inherit SKILL;

// void create() { seteuid(getuid()); }

mapping *action = ({
([      "action": "$N使一招「灵蛇摆尾」，全身骤然一抖，把$n摔倒在地",
	"dodge": -30,
	"parry": 10,
	"force": 20,
	"skill_name" : "灵蛇摆尾",
	"damage_type": "瘀伤"
]),
([      "action": "$N左掌内旋，一招「神龙现身」沾顾$n的手腕，同时展臂摇膀，横击$n的前胸",
	"dodge": -15,
	"parry": -20,
	"force": 30,
	"skill_name" : "神龙现身",
	"damage_type": "瘀伤"
]),
([      "action": "$N右掌外翻，掌心向上，左掌内翻掌心反向上，一招「双龙绞尾」，\n"
		  "抓住$n的手臂，互相绞力",
	"dodge": -10,
	"parry": -10,
	"force": 30,
	"skill_name" : "双龙绞尾",
	"damage_type": "瘀伤"
]),
([      "action": "$N双掌交叉，使一招「双龙抢珠」，上搠$n的手臂，右脚前踢$n的右小腿",
	"dodge": -5,
	"parry": 0,
	"force": 60,
	"skill_name" : "双龙抢珠",
	"damage_type": "瘀伤"
]),
([      "action": "$N立肘外旋内裹，向左滚推$n的手臂，右手握拳外旋直冲$n的面部，"
		   "一招「虎踞龙盘」",
	"dodge": 0,
	"parry": 10,
	"force": 50,
	"skill_name" : "虎踞龙盘",
	"damage_type": "瘀伤"
]),
([      "action": "$N右脚虚点，左腿上搠$n的门面，同时右脚反踢$n的腰，「马踩游蛇」",
	"dodge": 10,
	"parry": 20,
	"force": 60,
	"skill_name" : "马踩游蛇",
	"damage_type": "瘀伤"
]),
([      "action": "$N右手虚按$n背部，突然回身、摆步、拧腰、抡臂劈打，一记「龙起湖心」\n"
		  "猛击$n的$l",
	"dodge": 20,
	"parry": 20,
	"force": 80,
	"skill_name" : "龙起湖心",
	"damage_type": "瘀伤"
]),
([      "action": "$N弧线跨步，一招「龙卧高山」，钩踢$n的裆部",
	"dodge": 25,
	"parry": 10,
	"force": 20,
	"skill_name" : "龙卧高山",
	"damage_type": "瘀伤"
]),
([      "action": "$N提膝击$n的腿膝，使一招「地动山摇」，出其不意使$n失去重心",
	"dodge": 25,
	"parry": 20,
	"force": 50,
	"skill_name" : "地动山摇",
	"damage_type": "瘀伤"
]),
([      "action": "$N速出右拳沿$n右臂滚动，一招「直串龙潭」，边滚边向下直压$n的身体",
	"dodge": 30,
	"parry": 20,
	"force": 60,
	"skill_name" : "直串龙潭",
	"damage_type": "瘀伤"
]),
([      "action": "$N出右拳，左手由自己的右臂向前向上翻绕$n的右臂，一招「闪现雷鸣」",
	"dodge": 20,
	"parry": 30,
	"force": 20,
	"skill_name" : "闪现雷鸣",
	"damage_type": "瘀伤"
]),
([      "action": "$N速上右步，双手摆动迷惑$n，一招「水拍云崖」，\n"
		  "右腿在手的掩护下横击$n的两肋",
	"dodge": 20,
	"parry": 20,
	"force": 60,
	"skill_name" : "水拍云崖",
	"damage_type": "瘀伤"
]),
([      "action": "$N凝神聚气，以意念转动脊椎，右手一记「龟蛇竟渡」，\n"
		  "以不可抗拒之力击向$n的全身",
	"dodge": 15,
	"parry": 20,
	"force": 80,
	"skill_name" : "龟蛇竟渡",
	"damage_type": "瘀伤"
]),
([      "action": "$N出右手与$n的手臂相触，突然翻掌握$n手腕，\n"
		  "使出「倒索攀山」，向旁拉带$n",
	"dodge": 25,
	"parry": 30,
	"force": 50,
	"skill_name" : "倒索攀山",
	"damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return  usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="jueming-tui"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练化骨绵掌必须空手。\n");

/*
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("你的毒龙大法火候不够，无法练化骨绵掌。\n");
*/

        if( (int)me->query("sg/exp") < 5000 )
                return notify_fail("这是神龙教长老们的秘技，你必须借助神龙教练功房练习提高。\n");

        if( (int)me->query_con() < 30 )
                return notify_fail("你的根骨欠弱，难于练习化骨绵掌。\n");

        if( (int)me->query_skill("force") < (int)me->query_skill("huagu-mianzhang", 1)  )
                return notify_fail("你的内功修为还不足于继续练习化骨绵掌。\n");

        if( (int)me->query("max_neili") * 2 < (int)me->query_skill("huagu-mianzhang", 1) * 3 || (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力太弱，无法练化骨绵掌。\n");
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
	level  = (int)me->query_skill("huagu-mianzhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query_skill("huagu-mianzhang", 1) < 100 
        &&  base_name(environment(me)) != "/d/shenlong/liangongfang" )
                return notify_fail("你现在的化骨绵掌功力还不足于自行练习。\n");
               
	if ((int)me->query("jingli") < 100)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练化骨绵掌。\n");
	me->receive_damage("jingli", 60);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huagu-mianzhang/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
 //       object ob;
        int amount;
/*
	if( random(me->query_skill("huagu-mianzhang", 1)) > 30 ) {
		victim->apply_condition("sl_poison",
		random(me->query_skill("huagu-mianzhang", 1)/3) + (victim->query_condition("sl_poison")) );
	}

        if( ob = find_player("aln") )
        tell_object(ob, "\ndamage_bonus = " + damage_bonus + ".\n");
*/

        if( random(damage_bonus) > (int)victim->query_skill("force") / 2
        &&  !victim->query_temp("hgmz") )  {
                victim->set_temp("hgmz", 1);
                amount = 5 * damage_bonus/( 1 + victim->query_con()) + 1;
				amount = amount/100;
                victim->add_temp("apply/strength", -amount);
                victim->start_call_out( (: call_other, __FILE__, "remove_effect", victim, me, amount :), (int)me->query_skill("huagu-mianzhang", 1) / 10);
                message_vision(HIB"\n$N登时头晕目眩，立时便欲呕吐，喉间“呃呃呃”的不住作声。\n"NOR, victim);
        }
}

void remove_effect(object victim, object me, int amount)
{
        victim->delete_temp("hgmz");
        victim->add_temp("apply/strength", amount);
        message_vision(HIB"\n$N胸腹间气血翻涌，“哇”的一声，又是鲜血，又是清水，大口吐了出来。\n"NOR, victim);
        if( me )
        victim->receive_wound("qi", amount * 10 + random(amount * 10), me);
        else
        victim->receive_wound("qi", amount * 10 + random(amount * 10),
                "化骨绵掌毒发身亡");
}

