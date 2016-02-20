//Cracked by Roath
#include <mudlib.h>
#include <ansi.h>

inherit SKILL;
inherit F_DAMAGE;
mapping *action = ({
([      "action" : "$N阴阴地笑了笑，反手抓向$n的$l",
        "dodge": 10,
        "force": 40,
//      "poison": 80,
        "damage": 0,
        "lvl" : 0,  
        "damage_type": "抓伤"
]),
([      "action" :
 "$N突然倒下装死，就在$n疑惑不定之间，猛然跃起，双手抓向$n的面门",
        "dodge": 10,
	"parry": 10,
        "force": 160,
//      "poison": 100,
        "damage": 40,
        "lvl" : 10,
	"weapon": "五根手指",
        "damage_type": "刺伤"
]),
([      "action" :"$N宛若一条蜈蚣，在地上快速爬了几步，绕到$n身后，一爪抓下",
        "dodge": 15,
        "parry": 15,
        "force": 180,
//      "poison": 100,
        "damage": 40,
        "lvl" : 18,
        "damage_type": "抓伤"
]),

([      "action" : "$N脸上隐隐泛出绿色，一显即逝，右爪探向$n",
        "dodge": 5,
        "parry": 25,
        "force": 200, 
//      "poison": 120,
        "damage": 45,
        "lvl" : 26,
        "damage_type": "内伤"
]),     
([      "action" :"$N轻轻的对着$n脸上吹了一口气，$n瞬间方寸大乱，$N借机连向$n胸前抓了数下\n",

        "dodge": 15,
        "parry": 30,
        "force": 280,
//      "poison": 160,
        "damage": 60,
        "lvl" : 36, 
        "damage_type": "抓伤"
]),
([      "action" : "$N绕着$n快速的转了几圈，暴喝一声，掌爪互逆，几道冷风从指端射出，袭向$n\n",
        
        "dodge": 10,
        "parry": 25,
        "force": 350,
//      "poison": 200,
        "damage": 70,
        "lvl" : 45, 
        "damage_type": "抓伤"
]),

([      "action" : "$N身影忽前忽後，突然一转身左手往$n的$l拢去",
        "dodge": 25,
        "parry": 15,
        "force": 420,
//      "poison": 240, 
        "damage": 75,
        "lvl" : 55,
        "damage_type": "内伤"
]),

([      "action" : "$N使出一招「抽髓手」，十指泛出隐隐的蓝色光芒，搭住$n身躯，有如附骨之蛆",
        "dodge": 20,
        "parry": 45,
        "force": 450,
//      "poison": 300,
        "damage": 85,
        "lvl" : 63, 
	"skills_name" : "抽髓手",
        "damage_type": "抓伤"
])
});
int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="chousui-zhang"; }

int valid_learn(object me)
{
	
        int  nb,  nh;
      /*  nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("sanyin-zhua", 1);

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三阴蜈蚣爪必须空手。\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("你的化功大法火候不够，无法学三阴蜈蚣爪。\n");
	if ( nb < 100 && nb <= nh )
                return notify_fail("你的毒技修为不够，无法提高三阴蜈蚣爪。\n");
*/
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练三阴蜈蚣爪。\n");
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
        level   = (int) me->query_skill("juehu-zhua",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	int  nb,  nh;
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("sanyin-zhua", 1);

        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够！\n");
/*	if ( nb < 100 && nb <= nh )
                return notify_fail("你的毒技修为不够，无法提高三阴蜈蚣爪。\n");
*/
        me->receive_damage("jingli", 30);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lv,myexp,tarexp;
	lv = (int)me->query_skill("juehu-zhua",1);
	myexp = me->query("combat_exp");
	tarexp = victim->query("combat_exp");
	if ( random(lv) >200 && myexp > (int)(tarexp*1.5))
	{
	if (victim->query("gender") == "男性")
	{
	me->add("max_neili", -10);
	victim->set("gender", "无性");
	me->set("neili", 0);
	return HIR "$N咬破舌尖，运起全身功力向$n下身抓去。。。\n" NOR;
	}
	else 
	{
	victim->receive_wound("qi", lv*2);
        me->add("max_neili", -3);
        me->set("neili",0);  
        return HIR "$n只觉腰眼上一阵巨痛，被狠狠抓出一个血窟隆\n" NOR;
        }
	}
}

