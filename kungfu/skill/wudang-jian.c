//Cracked by Roath
// wudang-jian.c 武当剑法
// xQin 12/98

#include <ansi.h>
#include <combat.h>

inherit SKILL;

int raozhi(object me, object victim, object weapon, int damage);
nomask int parry_available() { return 1; }

string *parry_msg = ({
	"$p已大落下风，但一口$W仍将门户守得严密异常。\n",
	"$p剑走轻灵，削$P手指，$N急忙闪身避开。\n",
	"$p微一凝神，一柄$W四面八方把自身笼罩住了，使$P再也攻不进来。\n",
	"$p剑锋急转，护住中路，疾退一步，堪堪避开。\n",
	"$p连连倒退，从离宫踏进乾位，走坎宫，踏震位，消去$P凌厉攻势。\n",
	"$p见来势沉猛，不敢硬架，滑出一步，$W「横云断峰」斜扫$P。\n",
	"$p$W「流星坠地」直立向下挡架。\n",
	"$p右肩测过，「彩虹经天」，$W上撩。\n",
	"$p竟不退避，回剑斜撩，一招「斜阳一抹」，反削$P手指。\n",
	"$p不及闪避，只得一剑「斗柄南指」向$P胸口刺去，$N急忙侧身让过。\n",
});

string query_parry_msg(object weapon, object victim)
{
	object ob;

	if( !objectp(ob = victim->query_temp("weapon"))
	|| ob->query("skill_type") != "sword" || victim->query_skill("wudang-jian", 1) < 100 )
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", ob->name());
}

mapping *action = ({
([      "action": "$N剑法迅捷，$w「云横秦岭」，画了个圈子，一剑栏腰削去。$w如影随形，直刺$n$l",
        "force" : 100,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "云横秦岭",
        "damage_type": "刺伤"
]),
([      "action": "$N当下剑交左手，一路左手剑向$n逼去，$w「白虹贯日」向$l刺去，剑势凌厉",
        "force" : 120,
        "dodge" : -10,
        "damage": 30,
        "lvl" : 10,
        "skill_name" : "白虹贯日",
        "damage_type": "刺伤"
]),
([      "action": "$N「春云乍展」，挺剑疾刺$n$l，一柄$w施展开来，有如飞絮游丝，长河流水，轻灵连绵",
        "force" : 140,
        "dodge" : 10,
        "damage": 25,
        "lvl" : 20,
        "skill_name" : "春云乍展",
        "damage_type": "刺伤"
]),
([      "action": "$N突然跃起，回手就是一剑「天坤倒悬」，这一剑又快又准，寒光闪处，剑锋已及$n$l",
        "force" : 170,
        "dodge" : 5,
        "damage": 35,
        "lvl" : 30,
        "skill_name" : "天坤倒悬",
        "damage_type": "刺伤"
]),
([      "action": "$N当下抢到$n左首，$w「天外来云」，$w寒光起处，嗤嗤嗤一阵破空之声，向$n左右连刺",
        "force" : 190,
        "dodge" : -10,
        "damage": 40,
        "lvl" : 40,
        "skill_name" : "天外来云",
        "damage_type": "刺伤"
]),
([      "action": "倏地$N一招「耿耿银河」，$w一剑横削，随即千头绪般乱点下来，真如天上繁星一般",
        "force" : 210,
        "dodge" : 20,
        "damage": 45,
        "lvl" : 50,
        "skill_name" : "耿耿银河",
        "damage_type": "刺伤"
]),
([      "action": "$N向$n刷刷两剑，「满天花雨」四下圈挥，$w出手，连绵不断，俱是进手招数，攻势凌厉之极",
        "force" : 230,
        "dodge" : 0,
        "damage": 55,
        "lvl" : 60,
        "skill_name" : "满天花雨",
        "damage_type": "刺伤"
]),
([      "action": "$N$w横架头顶，一个「凤凰展翅」，$w一圈，但见$P剑走轻灵，光闪如虹，吞吐开阖之际，又飘逸，又凝重",
        "force" : 250,
        "dodge" : 10,
        "damage": 45,
        "lvl" : 70,
        "skill_name" : "凤凰展翅",
        "damage_type": "刺伤"
]),
([      "action": "蓦地里青光一闪，一柄$w从$N手中掷出，急飞向$n，如风驰电掣般射向$p$l，却是一招「银河横空」",
        "force" : 280,
        "dodge" : 0,
        "damage": 50,
        "lvl" : 80,
        "skill_name" : "银河横空",
        "damage_type": "刺伤"
]),
([      "action": "呛啷啷一声，剑光闪闪，$w递出，$N目视剑尖，心无旁鹜，含胸拔背、沉肩坠肘，摆了一招「万岳朝宗」的姿式",
        "force" : 300,
        "dodge" : -5,
        "damage": 50,
        "lvl" : 90,
        "skill_name" : "万岳朝宗",
        "damage_type": "刺伤"
]),
([      "action": "$N手舞$w，剑光闪烁，$w越使越快，突然间转身过来，一声呼喝，刷的一剑，刺向$n$l。这一招「顺水推舟」，正是武当剑法的绝招",
        "force" : 320,
        "dodge" : 0,
        "damage": 55,
        "lvl" : 100,
        "skill_name" : "顺水推舟",
        "damage_type": "刺伤"
]),
([      "action": "$N一声清啸，$w递出，指向$n。一招「手挥五弦」，剑尖嗡嗡连响，自右至左、由上而下的连晃五下，快得异乎寻常",
        "force" : 350,
        "dodge" : 0,
        "damage": 65,
        "lvl" : 110,
        "skill_name" : "手挥五弦",
        "damage_type": "刺伤"
]),
([      "action": "$N$w一起，使一招「百鸟朝凰」，但见剑尖乱颤，霎时间便如化为数十个剑尖，罩住$n中盘，这一招虽然厉害，但仍是彬彬有礼的剑法",
        "force" : 380,
        "dodge" : 10,
        "damage": 75,
        "lvl" : 120,
        "skill_name" : "百鸟朝凰",
        "damage_type": "刺伤"
]),
});

int valid_enable(string usage)
{
	return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query_skill("sword", 1) < 30 )
		return notify_fail("你对剑法的认识还不够。\n");

	if( (int)me->query_skill("wudang-jiuyang", 1) < 50 )
		return notify_fail("你的武当九阳功火候太浅。\n");
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
	int i, level;
	object victim;
	string *limbs, limb, msg;

	level = (int)me->query_skill("wudang-jian", 1);
	if( objectp(victim = me->select_opponent()) )
	{
		limbs = victim->query("limbs");
		limb = limbs[random(sizeof(limbs))];
	}
	
	if( random(me->query_temp("wudang/raozhi")) > 50 || me->query_temp("raozhi_attack") ) 
	{
		switch( me->query_temp("raozhi_attack") )
		{
			case 1: msg = "不料铮的一声轻响，$w反弹过来，直刺向$p$l";
				break;
			case 2: msg = HIC"谁知$N於$w"HIC"上连催两重劲，剑弯成弧，又是一弯，便如长蛇之游，奇诡不可设想"NOR;
				break;
			default: msg = HIW"突然间$N$w"HIW"破空，疾刺$n"+limb+"，剑到中途，剑尖微颤，竟然弯了过去，斜刺$p$l"NOR;
				break;
		}

		me->add_temp("wudang/raozhi", -1); 
		me->add("neili", -25);

		if( wizardp(me) )
			tell_object(me, sprintf("\nap: %d", COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK)));

		return ([
			"action": msg,
			"force" : 350+random(100),
			"dodge" : 10,
			"damage": 100+random(50),
			"damage_type":"刺伤",
			"post_action": (: raozhi :)
			]);
	}

	for( i = sizeof(action); i > 0; i-- )
		if( level > action[i-1]["lvl"] )
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon = me->query_temp("weapon");

	if( !objectp(weapon) || (string)weapon->query("skill_type") != "sword" )
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("jingli") < 50 )
		return notify_fail("你的体力不够练习武当剑法。\n");

	me->receive_damage("jingli", 30, "体力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"wudang-jian/" + action;
}

int raozhi(object me, object victim, object weapon, int damage)
{
	int level = (int)me->query_skill("wudang-jian", 1)/2;
	string ductile = weapon->query("id");

	me->add_temp("raozhi_attack", 1);

	if( damage == RESULT_DODGE && me->query_temp("raozhi_attack") < 3 ) 
	{
		me->add_temp("apply/attack", level);

		if( me->query_temp("raozhi_attack") == 1 ||
			( (ductile == "bailong jian" || ductile == "ruanjian"
				|| ductile == "shuixin jian") && me->query("neili") > 500 ) )
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		else me->delete_temp("raozhi_attack");

		me->add_temp("apply/attack", -level);
		return 1;
	}
	else me->delete_temp("raozhi_attack");
	return 1;
}

/*
$P柔云剑术连绵不断，一招既出，第二招顺势跟着就来，如柔丝不断，春云绵绵。
*/
/*
谁知子宁於剑上连催两重劲，剑弯成弧，又是一弯，便如长蛇之游，奇诡不
可设想。寻常长剑只能弯成一弧，如何能如至柔如水的水心剑，连受两道相
反力劲而不折？管公明全然想不到这一剑能如此刺到，危急万分的当口扭头
一侧，似水寒光一带，颈部斜斜带过一剑，鲜血直洒上天。
copyright by 《天山山庄》 http://members.xoom.com/seisuke/
*/
