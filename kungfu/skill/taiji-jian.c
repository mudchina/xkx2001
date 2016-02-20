//Cracked by Roath
// taiji-jian.c 太极剑
// cleansword 2/15/96
// Marz 5/21/96
// Fang 6/30/96
// xQin 3/99
// Modified 6/00 -xQin
#include <ansi.h>
#include <combat.h>

inherit SKILL;
inherit F_SSERVER;

int taiji(object me, object victim, object weapon, int damage);
int raozhi(object me, object victim, object weapon, int damage);
nomask int parry_available() { return 1; }

string *parry_msg = ({
	"$p左手剑诀斜引，$W横过，画了个半圈，平搭在$P$w之上，劲力传出，$w登时一沉。\n",
	"$p$W交左手，在身前划了两个圆圈，$P见$p剑劲连绵，护住全身，竟无半分空隙。\n",
	"$p剑招未曾使老，已然圈转。突然之间，$P眼前出现了几个白色光圈，大圈小圈，正圈斜圈，闪烁不已。$P眼睛一花，只好回招。\n",
	"$p当下凝神专志，将一套太极剑法使得圆转如意，严密异常的守住门户。\n",
	"$p以太极剑中「云麾三舞」三式解开。$P见$p化解时举重若轻，深得内家剑术三昧，不待$p回手，跳开一步。\n"
});

string query_parry_msg(object weapon, object victim)
{
	object ob;

	if( !objectp(ob = victim->query_temp("weapon")) || ob->query("skill_type") != "sword"
	|| victim->query_skill_mapped("sword") != "taiji-jian"
	|| victim->query_skill("taiji-jian", 1) < 100 )
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", ob->name());
}

mapping *action = ({
([	"action": "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
	"force" : 120,
	"dodge" : 20,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "蜻蜓点水",
	"damage_type": "刺伤"
]),
([	"action": "$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l",
	"force" : 140,
	"dodge" : 15,
	"damage": 15,
	"lvl" : 5,
	"skill_name" : "指南针",
	"damage_type": "刺伤"
]),
([	"action": "$N右脚独立，一招「大魁星」，$w由前向后反刺$n的$l",
	"force" : 160,
	"dodge" : 10,
	"damage": 15,
	"lvl" : 10,
	"skill_name" : "大魁星",
	"damage_type": "刺伤"
]),
([	"action": "$N一招「探海式」，右脚独立，左膝提起，$w向前抡劈$n的$l",
	"force" : 180,
	"dodge" : 5,
	"damage": 20,
	"lvl" : 15,
	"skill_name" : "探海式",
	"damage_type": "劈伤"
]),
([	"action": "$N一招「燕子抄水」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"force" : 200,
	"dodge" : 15,
	"damage": 25,
	"lvl" : 20,
	"skill_name" : "燕子抄水",
	"damage_type": "割伤"
]),
([	"action": "$N一招「乌龙摆尾」，右脚变虚步，右手回收，$w向下截劈$n的$l",
	"force" : 220,
	"dodge" : 10,
	"damage": 25,
	"lvl" : 25,
	"skill_name" : "乌龙摆尾",
	"damage_type": "劈伤"
]),
([	"action": "$N一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$n的$l",
	"force" : 190,
	"dodge" : 10,
	"damage": 30,
	"lvl" : 30,
	"skill_name" : random(2)?"右拦扫":"左拦扫",
	"damage_type": random(2)?"刺伤":"劈伤"
]),
([	"action": "$N右脚向前一步，左膝提起，一招「宿鸟投林」，$w向前上方刺向$n的$l",
	"force" : 210,
	"dodge" : 15,
	"damage": 35,
	"lvl" : 35,
	"skill_name" : "宿鸟投林",
	"damage_type": "刺伤"
]),
([	"action": "$N使一招「青龙出水」，右脚向后回撤，$w随身体右后撤，突然向左前方刺向$n的$l",
	"force" : 230,
	"dodge" : 5,
	"damage": 40,
 	"skill_name" : "青龙出水",
	"damage_type": "刺伤"
]),
([	"action": "$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
	"force" : 240,
	"dodge" : 10,
	"damage": 40,
	"lvl" : 45,
	"skill_name" : "三环套月",
	"damage_type": "割伤"
]),
([	"action": "$N一转身，$w向后斜带，一招「风卷荷叶」，砍向$n的$l",
	"force" : 260,
	"dodge" : 5,
	"damage": 45,
	"lvl" : 50,
	"skill_name" : "风卷荷叶",
	"damage_type": "劈伤"
]),
([	"action": "$N左脚独立，右膝提起，双手捧剑，一招「虎抱头」，缓缓刺向$n的$l",
	"force" : 260,
	"dodge" : 10,
	"damage": 40,
	"lvl" : 55,
	"skill_name" : "虎抱头",
	"damage_type": "刺伤"
]),
([	"action": "$N一缩身，剑向回带，一招「狮子摇头」，抹向$n的$l",
	"force" : 280,
	"dodge" : 15,
	"damage": 45,
	"lvl" : 60,
	"skill_name" : "狮子摇头",
	"damage_type": "割伤"
]),
([	"action": "$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，逼向$n的$l",
	"force" : 280,
	"dodge" : 10,
   	"damage": 50,
	"lvl" : 65,
	"skill_name" : "仙人指路",
	"damage_type": "刺伤"
]),
([	"action": "$N向前连跳两步，一招「野马跳涧」，$w向前平刺$n的$l",
	"force" : 300,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 70,
	"skill_name" : "野马跳涧",
	"damage_type": "刺伤",
]),
([	"action": "$N一招「射雁式」，左脚跃步落地，$w回抽，反手勾向$n的$l",
	"force" : 320,
	"dodge" : 10,
	"damage": 50,
	"lvl" : 75,
	"skill_name" : "射雁式",
	"damage_type": "割伤"
]),
([	"action": "$N摆一个左虚步，$w划一个整圆，一式「小魁星」撩向$n的$l",
	"force" : 320,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 80,
	"skill_name" : "小魁星",
	"damage_type": "刺伤",
]),
([	"action": "$N双脚并步，身体立起，一招「白猿献果」，$w向前平刺$n的$l",
	"force" : 360,
	"dodge" : 0,
	"damage": 60,
	"lvl" : 85,
	"skill_name" : "白猿献果",
	"damage_type": "刺伤"
]),
([	"action": "$N左脚向前进一步，$w由后划一整圆向前托起，一招「迎风掸尘」，刺向$n的$l",
	"force" : 360,
	"dodge" : 5,
	"damage": 65,
	"lvl" : 90,
	"skill_name" : "迎风掸尘",
	"damage_type": "刺伤"
]),
([	"action": "$N左脚前进一步，右手$w一招「顺水推舟」，向右后方刺向$n的$l",
	"force" : 360,
	"dodge" : 0,
	"damage": 70,
	"lvl" : 95,
	"skill_name" : "顺水推舟",
	"damage_type": "刺伤"
]),
([	"action": "$N一反身，使一招「流星赶月」，回劈$n的$l",
	"force" : 380,
	"dodge" : 5,
	"damage": 75,
	"lvl" : 100,
	"skill_name" : "流星赶月",
	"damage_type": "劈伤"
]),
([	"action": "$N右脚向前垫步，一招「海底捞月」，剑由上向后划一个大弧，向前撩向$n的$l",
	"force" : 380,
	"dodge" : 0,
	"damage": 80,
	"lvl" : 105,
	"skill_name" : "海底捞月",
	"damage_type": "刺伤"
]),
([	"action": "$N右脚独立，右手$w向后撤，再向前平平托起，一招「挑帘式」刺向$n的$l",
	"force" : 400,
	"dodge" : -5,
	"damage": 85,
	"lvl" : 110,
	"skill_name" : "挑帘式",
	"damage_type": "刺伤"
]),
([	"action": "$N提起左腿转身垫步，右脚跟进，一招「黄峰入洞」，$w中宫直进，刺向$n的$l",
	"force" : 420,
	"dodge" : -5,
	"damage": 90,
	"lvl" : 115,
	"skill_name" : "黄峰入洞",
	"damage_type": "刺伤"
]),
([	"action": "$N右脚后撤一步，一转身，右手$w向后反击，一招「大鹏展翅」，抹向$n的$l",
	"force" : 420,
	"dodge" : -10,
	"damage": 95,
	"lvl" : 120,
	"skill_name" : "大鹏展翅",
	"damage_type": "割伤"
]),
([	"action": "$N一个弓步挂劈，再一个虚步抡劈，左右「车轮剑」，绵绵不绝劈向$n的$l",
	"force" : 450,
	"dodge" : -5,
	"damage": 100,
	"lvl" : 125,
	"skill_name" : "车轮剑",
	"damage_type": "劈伤"
]),
([	"action": "$N一招「天马行空」，向前跃落，右手$w由上向前劈下，飘逸地点向$n的$l",
	"force" : 450,
	"dodge" : -10,
	"damage": 120,
	"lvl" : 130,
	"skill_name" : "天马行空",
	"damage_type": "刺伤",
]),
([	"action": "$N使一招「风扫梅花」，身体不停地旋转，右手$w随身转动，风雷电掣般向$n的$l扫去",
	"force" : 450,
	"dodge" : -15,
	"damage": 100,
	"lvl" : 135,
	"skill_name" : "风扫梅花",
	"damage_type": "劈伤"
]),
});

string *taiji_msg = ({
	"$N当下左足踏上，剑交左手，一招「三环套月」，虚虚实实，以左手剑攻敌，剑尖上光芒闪烁，嗤嗤嗤的发出轻微响声",
	"$N剑法吞吐开合、阴阳动静，将太极剑法中最精要之处都发挥了出来，功劲一加运开，绵绵不绝",
	"$N左手$w缓缓向前划出，成一弧形。$n只觉一股森森寒气，直逼过来",
	"$N右手捏著剑诀，左手$w不住抖动，突然平刺，剑尖急颤，看不出攻向何处。$P这一招中笼罩了$n上盘七大要穴",
	"$N剑招未曾使老，已然圈转。突然之间，$n眼前出现了几个白色光圈，大圈小圈，正圈斜圈，闪烁不已",
	"$N剑上所幻的光圈越来越多，过不多时，$P全身已隐在无数光圈之中，光圈一个未消，另一个再生。\n$w虽使得极快，却听不到丝毫金刃劈风之声，足见剑劲之柔韧已达於化境",
	"$n只觉似有千百柄$w护住了$N全身。$N纯采守势，端的是绝无破绽。\n可是这座剑锋所组成的堡垒却能移动，千百个光圈犹如浪潮一般，缓缓涌来",
	"$N并非一招一招的相攻，而是以数十招剑法混成的守势，同时化为攻势，使$n无法抵御"
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_skill("taiji-shengong", 1) < 20 )
		return notify_fail("你的太极神功火候太浅。\n");
	if( (int)me->query_skill("mian-zhang", 1) < 20 )
		return notify_fail("你的绵掌火候太浅。\n");
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
	int i, level, busy_time;
	object victim;
	string *limbs, limb, target, msg;

	level = (int)me->query_skill("taiji-jian", 1);
	busy_time = level/20;
	if( objectp(victim = me->select_opponent()) )
	{
		limbs = victim->query("limbs");
		limb = limbs[random(sizeof(limbs))];
		target = victim->name();
	}

	if( me->query_temp("double_attack") )
	{
		return ([
		"action": "突然之间，$N剑交右手，寒光一闪，向$n$l划出，这一下快速无伦",
		"force" : 350+random(100),
		"dodge" : 20,
		"damage": 100+random(50),
		"damage_type" : "割伤" ]);
	}

	if( me->query_temp("chan/"+target) )
	{
		victim->start_busy(2);
		me->add("neili", -20);
		me->add_temp("chan/"+target, 1);

		if( me->query_temp("chan/"+target) >= busy_time )
			me->delete_temp("chan/"+target);
	}

	if( me->query_temp("taiji") && me->query("neili") > 100 )
	{
		me->add_temp("taiji_fight", 1);
		me->add("neili", -10);
		return ([
		"action": taiji_msg[random(sizeof(taiji_msg))],
		"force" : 420+random(120),
		"dodge" : 100+random(50),
		"damage": 120+random(80),
		"damage_type" : random(2)?"刺伤":"割伤",
		"post_action" : (: taiji :) ]);
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
			"force" : 380+random(120),
			"dodge" : 10,
			"damage": 120+random(80),
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
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword" )
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("jingli") < 50 )
		return notify_fail("你的精力不够练太极剑法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}

int taiji(object me, object victim, object weapon, int damage)
{
	int n = random(2);

	if( damage == RESULT_DODGE ) 
	{
		if( n == 0 && me->query_skill_mapped("cuff") == "taiji-quan"
		&& me->query_skill_prepared("cuff") == "taiji-quan" )
		{
			me->set_temp("double_attack", 1);
			weapon->unequip();
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
			weapon->wield();
		}
		else
		{
			me->set_temp("double_attack", 2);
			COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
			message_vision("\n$N又是剑交左手，在身前划了两个圆圈。$n见$P剑劲连绵，护住全身，竟无半分空隙。\n", me, victim);
		}
		me->delete_temp("double_attack");

		return 1;
	}
	else if( damage <= 0 )
	{
		message_vision("$p但觉$P剑上有股绵劲，震得自己手臂隐隐发麻。\n", me, victim);
		if( !victim->is_busy() )
			victim->start_busy(1+random((int)(me->query_skill("force")/150)));
		victim->add("neili", -(int)(me->query_skill("force")/10));
	}
	return 1;
}
int raozhi(object me, object victim, object weapon, int damage)
{
	int level = (int)me->query_skill("taiji-jian", 1)/2;
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


