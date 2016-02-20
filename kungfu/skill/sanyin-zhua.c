//Cracked by Roath
// sanyin-zhua.c -三阴蜈蚣爪
//aska dec,2 1996
//wsky march 7th 2000

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N阴阴地笑了笑，伸手虚击$n的面门，趁$n全力招架之际，一转身，反手抓向$n的$l",
        "dodge": 10,
        "force": 40,
//      "poison": 80,
        "damage": 20,
        "lvl" : 0,  
        "damage_type": "抓伤"
]),
([      "action" : "$N突然倒下装死，就在$n疑惑不定之间，猛然跃起，双手抓向$n的$l，$n大惊之下，不知所措",
        "dodge": 10,
        "parry": 10,
        "force": 160,
//      "poison": 100,
        "damage": 40,
        "lvl" : 10,
        "weapon": "五根手指",
        "damage_type": "刺伤"
]),
([      "action" :"$N扑地而倒，宛若一条蜈蚣，在地上快速爬了几步，绕到$n身后，一爪抓下",
        "dodge": 15,
        "parry": 15,
        "force": 180,
//      "poison": 100,
        "damage": 50,
        "lvl" : 18,
        "damage_type": "抓伤"
]),

([      "action" : "尖叫声中，$N脸上隐隐泛出绿色，一显即逝，右爪猛地探向$n的$l",
        "dodge": 5,
        "parry": 25,
        "force": 200, 
//      "poison": 120,
        "damage": 55,
        "lvl" : 26,
        "damage_type": "内伤"
]),     
([      "action" :"$N轻轻的对着$n脸上吹了一口气，$n瞬间方寸大乱，$N借机连向$n胸前抓了数下",

        "dodge": 15,
        "parry": 30,
        "force": 280,
//      "poison": 160,
        "damage": 60,
        "lvl" : 36, 
        "damage_type": "抓伤"
]),
([      "action" : "$N绕着$n快速的转了几圈，暴喝一声，掌爪互逆，几道冷风从指端射出，袭向$n",
        
        "dodge": 10,
        "parry": 25,
        "force": 350,
//      "poison": 200,
        "damage": 80,
        "lvl" : 45, 
        "damage_type": "抓伤"
]),

([      "action" : "$N身影忽前忽後，身形飘忽不定，突然一转身左手往$n的$l拢去",
        "dodge": 25,
        "parry": 15,
        "force": 420,
//      "poison": 240, 
        "damage": 75,
        "lvl" : 65,
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
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("sanyin-zhua", 1);

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三阴蜈蚣爪必须空手。\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("你的化功大法火候不够，无法学三阴蜈蚣爪。\n");
        if ( nb < 100 && nb <= nh )
                return notify_fail("你的毒技修为不够，无法提高三阴蜈蚣爪。\n");

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
        level   = (int) me->query_skill("sanyin-zhua",1);
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
        if ( nb < 100 && nb <= nh )
                return notify_fail("你的毒技修为不够，无法提高三阴蜈蚣爪。\n");

        me->receive_damage("jingli", 30);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int neili, neili2, cases, csz, par, mein, exp1, exp2;
        string result;
        neili=me->query("neili");
        neili2=victim->query("neili");
	exp1=me->query("combat_exp")/10000;
	exp2=victim->query("combat_exp")/10000;
	csz=me->query_skill("sanyin-zhua",1);
	par=victim->query_skill("parry",1);
	mein=0;
	
	if(csz>150){
	if (present("huo yan", environment(me))){
        	mein=13;
        	if(csz<150) cases=1;
        	else if (csz>=150 && csz<200) cases=3;
        	else cases=6;
        	switch(random(cases)){
        		case 0:
        		message_vision(HIR"\n$N一声狂吼，脸上红光一现，胸口狂涨，双手舞出一阵骤风，发着虎虎声响向$n攻去。"NOR,me,victim);
        		damage_bonus+=250+random(100);
        		return ([ "result" : result, "damage" : damage_bonus ]);
			break;
        		case 1:
        		message_vision(HIB"\n$N突然间掌法一变，左掌向右一抹，右掌嗖嗖嗖向$n击出三掌，$n身上一寒，退后一步。"NOR,me,victim);
        		damage_bonus+=250+random(150);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        		case 2:
        		message_vision(HIY"\n$N身行一晃，有如鬼魅，双掌拂起一道黄色火焰，迅速无比地向$n飞去。"NOR,me,victim);
        		damage_bonus+=250+random(200);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        		case 3:
        		message_vision(HIR"\n$N尖声狂叫，猛地咬破自己舌头，一口鲜血向$n喷去。$n刹时间不知所措，只得向后避开。"NOR,me,victim);
        		damage_bonus+=250+random(250);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        		case 4:
        		message_vision(HIW"\n$N左掌一晃，长袖扬起，$n突然间见到一丝白雾向自己袭来，觉得眼中一阵刺痛。"NOR,me,victim);
        		damage_bonus+=250+random(300);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        		case 5:
        		message_vision("\n$N"HIB"左掌阴"NOR"，"HIR"右掌阳"NOR"，"HIW"双袖卷起一阵劲风"NOR"，舞得火焰"HIG"五"HIY"颜"HIM"六"HIR"色"NOR"，漂亮无比。"NOR,me,victim);
        		damage_bonus+=250+random(400);
        		return ([ "result" : result, "damage" : damage_bonus ]);
			case 6:
        		message_vision("\n$N"HIB"左掌阴"NOR"，"HIR"右掌阳"NOR"，"HIW"双袖卷起一阵劲风"NOR"，舞得火焰"HIG"五"HIY"颜"HIM"六"HIR"色"NOR"，漂亮无比。"NOR,me,victim);
        		damage_bonus+=250+random(400);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        	}
        }}
	
        if(random(neili)>random(neili2)){
                message_vision(MAG"$n猛然觉得一阵寒气袭来，身子一晃，头脑微微有些发昏。\n"NOR, me, victim);
                victim->apply_condition("xx_poison", random(me->query_skill("sanyin-zhua", 1)/2) + victim->query_condition("xx_poison"));
                if(victim->query("poisoner") != me) victim->set("poisoner", me);
        } else message_vision(YEL"$n忙运内力抵抗，将$N爪上的剧毒逼在体外。\n"NOR,me,victim);
	
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("sanyin-zhua", 1) >= 100 )
                return __DIR__"sanyin-zhua/" + action;
}

