//Cracked by Roath
// 18-zhang.c
// Modified by xQin 1/99

#include <ansi.h>
#include <combat.h>
inherit SKILL;

int sanhui(object me, object victim, object weapon, int damage);

nomask int parry_available() { return 1; }
string *parry_msg = ({
	"$p不待回身，一招「神龙摆尾」，反手还劈一掌。$P见$n这招来势凶狠，不敢硬接，纵身避开。\n",
	"只见$p左掌圆劲，右掌直势，使招「见龙在田」，挡在身前。一招纯是防御，却是在双方之间布了一道坚壁。\n",
	"$p当下不敢怠慢，双掌飞舞，将自己全身笼罩在掌力之下。这一守当真是稳若渊停岳峙，直无半点破绽。\n",
});

string query_parry_msg(object weapon, object victim) 
{ 
	object me = victim->select_opponent();

        if ( victim->query_temp("weapon") || victim->query_skill("18-zhang", 1) < 100
        || victim->query_skill_prepared("strike") != "18-zhang" )
                return SKILL_D("parry")->query_parry_msg(weapon);
               
        else {
//		call_out("baiwei", 0, victim,me);
//		return parry_msg[random(sizeof(parry_msg))];

        string *slbw = ({
                "$n更不回身，右手一招「神龙摆尾」向后挥去，这是降龙十八掌中的救命绝招，$p在情急之下使将出来，更是威力倍增！！\n",
                "$n避让不及，不待回身，一招「神龙摆尾」，反手向$P还劈一掌！\n",
                "就在这一瞬之间，$p急忙转身，同时一招「神龙摆尾」向$P反手横劈！\n",
        });
		message_vision(YEL"\n"+slbw[random(sizeof(slbw))]+""NOR,me,victim);
		return COMBAT_D->do_attack(victim, me, me->query_temp("weapon")) + "";
                }
}
/*
void baiwei(object victim, object me) 
{
        string *slbw = ({
                "$n更不回身，右手一招「神龙摆尾」向后挥去，这是降龙十八掌中的救命绝招，$p在情急之下使将出来，更是威力倍增！！\n",
                "$n避让不及，不待回身，一招「神龙摆尾」，反手向$P还劈一掌！\n",
                "就在这一瞬之间，$p急忙转身，同时一招「神龙摆尾」向$P反手横劈！\n",
        });
        if (!me) return;
		message_vision(YEL"\n"+slbw[random(sizeof(slbw))]+""NOR,me,victim);
	        COMBAT_D->do_attack(victim, me, me->query_temp("weapon"));
}
*/
mapping *action = ({
([	"action": "$N使出「飞龙在天」，跃起半空，居高下击，威力奇大。双掌如刀似剪，掌掌往$n$l削去",
	"dodge": 20,
	"parry": 15,
	"force": 480,
	"damage": 25,
	"lvl": 5,
	"skill_name": "飞龙在天",
	"damage_type": "劈伤",
	"weapon" : "掌缘"
]),
([	"action": "$N急运劲力，双掌气势如虹，平推出去。这一招「见龙在田」又快又重，蕴力蓄劲，甚是凌厉",
	"dodge": 15,
	"parry": 25,
	"force": 400,
	"damage": 30,
	"lvl": 10,
	"skill_name": "见龙在田",
	"damage_type": "瘀伤"
]),
([	"action": "$N催加掌力，双掌齐发，施出一招「鸿渐于陆」，挟着一股劲风拍向$n$l，掌法精妙，力道沉猛，刚猛无俦，凌厉无伦",
	"dodge": 20,
	"parry": 20,
	"force": 330,
	"damage": 35,
	"lvl": 15,
	"skill_name": "鸿渐于陆",
	"damage_type": "瘀伤"
]),
([	"action": "$N弓背挺剑，矮身反打出掌。掌去如风，正是一招「神龙摆尾」，右掌力拍，左掌跟着一下，力道尤其沉猛",
	"dodge": 15,
	"parry": 25,
	"force": 600,
	"damage": 110,
	"lvl": 20,
	"skill_name": "神龙摆尾",
	"damage_type": "瘀伤"
]),
([	"action": "$N右手屈起食中两指，半拳半掌，向$n$l打去。那是一招「潜龙勿用」，左手同时向钩拿。右推左钩，使$p极难闪避",
	"dodge": 15,
	"parry": 25,
	"force": 450,
	"damage": 40,
	"lvl": 25,
	"skill_name": "潜龙勿用",
	"damage_type": random(2)?"擦伤":"瘀伤"
]),
([	"action": "$N右掌挡胸，左掌从胯间缓缓拾起，划了个半圈，伸向胸前。双掌虚捧成球，紧跟着向$n劈出一掌「利涉大川」",
	"dodge": 20,
	"parry": 20,
	"force": 380,
	"damage": 45,
	"lvl": 30,
	"skill_name": "利涉大川",
	"damage_type": "劈伤",
	"weapon" : "掌劲"
]),
([	"action": "$n忽见一条人影从旁扑来，人未到，掌先至，$N左掌拍出，使的是第十一掌「突如其来」",
	"dodge": 15,
	"parry": 25,
	"force": 400,
	"damage": 50,
	"lvl": 35,
	"skill_name": "突如其来",
	"damage_type": "瘀伤"
]),
([	"action": "$N一招「震惊百里」，双掌齐施，攻势犹似暴风骤雨一般，向$n直推过去，这是降龙十八掌中威力极大的一招",
	"dodge": 25,
	"parry": 15,
	"force": 420,
	"damage": 55,
	"lvl": 40,
	"skill_name": "震惊百里",
	"damage_type": "瘀伤"
]),
([	"action": "$N吸一口气，呼的一响，一掌「或跃在渊」，左掌前探，右掌倏地从左掌底下穿了过去，击向$n$l",
	"dodge": 30,
	"parry": 10,
	"force": 450,
	"damage": 60,
	"lvl": 45,
	"skill_name": "或跃在渊",
	"damage_type": "瘀伤"
]),
([	"action": "$N左掌高，右掌低，同时拍出，双掌呼呼声响，使成一个圈子，一招「双龙取水」，猛击$n$l",
	"dodge": 20,
	"parry": 20,
	"force": 470,
	"damage": 65,
	"lvl": 50,
	"skill_name": "双龙取水",
	"damage_type": "瘀伤"
]),
([	"action": "$N右掌前引，左掌从右手腕底穿出，使一招「鱼跃於渊」人已跃在半空，右掌复又翻到左掌之前，向$n一扑",
	"dodge": 30,
	"parry": 10,
	"force": 500,
	"damage": 70,
	"lvl": 55,
	"skill_name": "鱼跃於渊",
	"damage_type": "瘀伤"
]),
([	"action": "$N纵身向前，一招「时乘六龙」往$n连劈六掌，每一掌都是打得狂风呼啸，飞沙走石，力道非同小可",
	"dodge": 15,
	"parry": 25,
	"force": 520,
	"damage": 75,
	"lvl": 60,
	"skill_name": "时乘六龙",
	"damage_type": "劈伤",
	"weapon" : "掌风"
]),
([	"action": "$N使出一招「密云不雨」，前一掌，后一掌，绕着$n身周转动，霎时间$p全身已在$P掌力笼罩之下",
	"dodge": 20,
	"parry": 20,
	"force": 550,
	"damage": 80,
	"lvl": 65,
	"skill_name": "密云不雨",
	"damage_type": "瘀伤"
]),
([	"action": "$N使出「损则有孚」，双掌软绵绵地拍向$n$l，劲力忽强忽弱，忽吞忽吐，从至刚之中竟生出至柔的妙用",
	"dodge": 10,
	"parry": 30,
	"force": 580,
	"damage": 85,
	"lvl": 70,
	"skill_name": "损则有孚",
	"damage_type": "内伤"
]),
([	"action": "$N左臂横扫，逼到$n的身前，这招「龙战于野」十分巧妙。眼见$p挡$P左臂，右掌忽起，正击向$p$l之处",
	"dodge": 20,
	"parry": 20,
	"force": 600,
	"damage": 90,
	"lvl": 75,
	"skill_name": "龙战于野",
	"damage_type": "瘀伤"
]),
([	"action": "$N两肘往上微抬，右拳左掌，直击横推，一快一慢的打了出去，正是一招「履霜冰至」，一招之中刚柔并济，正反相成",
	"dodge": 25,
	"parry": 15,
	"force": 600,
	"damage": 95,
	"lvl": 80,
	"skill_name": "履霜冰至",
	"damage_type": random(2)?"内伤":"瘀伤"
]),
([	"action": "$N双手使一招「羝羊触蕃」，和身冲将过去，手掌一伸一缩，掌力吞吐，猛地里向$n$l斜推出去",
	"dodge": 20,
	"parry": 20,
	"force": 330,
	"damage": 20,
	"lvl": 85,
	"skill_name": "羝羊触蕃",
	"damage_type": "瘀伤"
]),
([	"action": "$N左腿微屈，右臂内弯，右掌划了个圆圈，呼的一声，向外推去，正是一招「亢龙有悔」",
	"dodge": -20,
	"parry": 25,
	"force": 650,
	"damage": 120,
	"lvl": 90,
	"skill_name": "亢龙有悔",
	"damage_type": "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练降龙十八掌必须空手。\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 20)
		return notify_fail("你的混天气功火候不够，无法练降龙十八掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
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
	int x = 1 + random(8);
	int y = 3 + random(10);

	string *sanhui_msg = 
	({
		"$N大步迈出，左手一划，右掌呼的一声，便向$n击去，正是一招「亢龙有悔」，力自掌生，猛不可当",
		"$N一掌既出，身子抢前，又是一招「亢龙有悔」，後掌推前掌，双掌力道并在一起，排山倒海的压将过来",
		"$N跟着又是一招「亢龙有悔」，前招掌力相消，次招掌力又至。竟如怒涛狂涌，势不可挡，又如一堵无形的高墙，向$n身前疾冲",
	});

	if ( me->query_skill_mapped("force") == "huntian-qigong" )
	{
		if ( me->query_temp("sanhui") > 0 && me->query_temp("sanhui") <= 3 )
		{
			return ([
			"action": sanhui_msg[me->query_temp("sanhui")-1],
			"dodge": -20,
			"parry": 25,
			"force": 650,
			"damage": 120,
			"damage_type": "瘀伤",
			"post_action": (: sanhui :) ]);
		}
		else if ( random(me->query_skill("strike")) > 280 && random(me->query_skill("force")) > 200 && me->query("neili") > 1000 && me->query("jiali") > 150 )
		{
			me->add("neili", -50);
			return ([
			"action": HIY"$N一招「亢龙有悔」，平推出去。初推出去看似轻描淡写，但一遇阻力，刹时之间连加"+ chinese_number(y) +"道後劲，一道强似一道，重重叠叠，直至无坚不摧，无强不破"NOR,
			"dodge": -20+random(20),
			"parry": 25+random(20),
			"force": 650+random(150),
			"damage": 120+random(50),
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
		else if ( random(me->query_skill("strike")) > 210 && random(me->query_skill("force")) > 150 && me->query("neili") > 500 && me->query("jiali") > 100 )
		{
			me->add("neili", -30);
			return ([
			"action": YEL"$N踏上两步，呼的一声，一招「亢龙有悔」当胸击去。这一掌"+ chinese_number(x) +"分发，"+ chinese_number(10-x) +"分收，劲道去而复回，实是非同小可"NOR,
			"dodge": -20+random(100),
			"parry": 25+random(100),
			"force": 650+random(50),
			"damage": 120+random(20),
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
	}

	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 40)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练降龙十八掌。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"18-zhang/" + action;
}
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( me->query_temp("sanhui") ) 
		me->delete_temp("sanhui");
}
*/

int sanhui(object me, object victim, object weapon, int damage)
{
	if( damage > 0 && me->query_temp("sanhui") ) 
		me->delete_temp("sanhui");
}

mapping *query_skilldbase() {return action;}