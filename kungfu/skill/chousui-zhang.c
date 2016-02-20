//Cracked by Roath
// chousui-zhang.c, 抽髓掌
// by yucao
// Ryu, 12/4/96.
// wsky, 13/06/00

#include <ansi.h>
inherit SKILL;

mapping *action = ({

([      "action" : "$N脸上露出诡异的笑容，身行微摆，以晃到$n的身后，隐隐泛出绿色的双掌扫向$n的$l",
        "force" : 125,
        "dodge" : 25,
        "parry" : 15,
        "damage_type" : "瘀伤",
        "lvl" : 0,
        "damage": 35,
//      "poison": 50,
        "skill_name" : "抽髓手",
]),
([      "action": "$N突然一身尖叫，身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
        "dodge": 10,
        "force": 150,
        "parry" : -25,
//      "poison": 60,
	"lvl" : 15,
	"damage": 45,
        "damage_type": "瘀伤",
        "skill_name" : "天山飞鹰",
]),
([      "action": "突然间$N脸色一沉，喉咙中发出古怪声响，将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l",
        "dodge": -20,
        "parry" : 35,
        "force": 175,
        "damage": 55,
//      "poison": 100,
	"lvl" : 30,
        "damage_type": "瘀伤",
        "skill_name" : "腐尸毒",
]),
([      "action": "$N左一转，右一转，身子滑溜之极，转眼间已经欺到$n身前，双掌挟着一股腥臭之气拍向$n的$l",
        "dodge": -10,
        "parry" : 15,
        "force": 195,
        "damage": 60,
//      "poison": 80
	"lvl" : 45,
	"damage_type": "瘀伤",
        "skill_name": "伤髓手",
]),
([      "action": "$N猛得跃起，大袖向$n挥去，趁$n一是慌乱之际，右掌运起毒功猛地向$n击去。",
        "dodge": 10,
        "parry" : -5,
        "force": 225,
        "damage": 65,
//      "poison": 80
	"lvl" : 60,
	"damage_type": "瘀伤",
        "skill_name": "必杀决",
]),
([      "action": "$N突然间扑地而倒，双腿向$n下阴踢去，趁$n躲闪之时，顺手抓起地上石头向$n的$l掷去",
        "dodge": 30,
        "parry" : -5,
        "force": 235,
        "damage": 70,
//      "poison": 80
	"lvl" : 80,
	"damage_type": "瘀伤",
        "skill_name": "连环一击",
]),
([      "action": "$N双目凶光大射，胸口高高股起，将所有内力运与掌中，拼命地向$n打去",
        "dodge": -30,
        "parry" : -5,
        "force": 235,
        "damage": 75,
//      "poison": 80
	"lvl" : 100,
	"damage_type": "瘀伤",
        "skill_name": "大擒拿",
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="sanyin-zhua"; }

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("chousui-zhang", 1);
        
        if (present("huo yan", environment(me))){
	        if (random(me->query_skill("strike")) > 250 && me->query("neili") > 1000 ) {
                	me->add("neili", -100);
			//victim->start_busy(random(3));
                	return ([
        	    		"action":BLU"$N神色惨淡，伸手打开发髻，长发下垂，覆在脸上，跟着力咬舌尖，"+HIR+"一口鲜"
                    		"血向火焰中喷去。\n那火焰忽地一暗，"+HIW+"随即大为明亮，$N猛地身子急旋，如陀"
                    		"螺般连转了十多个圈子，"+HIR+"大袖拂动，整个火焰堆陡地拨起，便如一座火墙般向$n压过去"NOR,
                		"force": 800,
                		"dodge": 50,
                		"weapon": "火焰",
                		"damage": 150,
                		"damage_type": "烧伤"]);
        	}
        	if (random(me->query_skill("strike")) > 215 &&
            		me->query("neili") > 800 ) {
                	me->add("neili", -75);
			//victim->start_busy(random(3));
                	return ([
        			"action":HIG"$N厉声大喝，掌力加盛，绿火突然化作一个"+HIR+"斗大的火球，向$n疾冲过来。使力极猛，去势奇快，"+HIG+"只见一碧绿的火球在空中骨碌碌的迅速转动"NOR,
                		"force": 600,
                		"dodge": 25,
                		"weapon": "火球",
                		"damage": 100,
                		"damage_type": "烧伤"]);
        	}
        	if (random(me->query_skill("strike")) > 180 &&
            		me->query("neili") > 600 ) {
                	me->add("neili", -50);
                	return ([
        			"action":HIR"$N衣袖一拂，一股劲气直射入火焰之中，"+HIG+"火焰中又分出一道细细的绿火，便如一根水线般，"
                 		+HIW+"$N衣袖挥动，两股劲风分袭$n左右"NOR,
                		"force": 500,
                		"dodge": 10,
                		"weapon": HIG"绿火"NOR,
                		"damage": 100,
                		"damage_type": "烧伤"]); 
        	}
        	if (random(me->query_skill("strike")) > 150 &&
            		me->query("neili") > 500 ) {
                	me->add("neili", -20);
                	return ([
       				"action":HIR"$N随即左掌斜拍出一道"+HIG+"绿火"+HIR+"向$n射去，声势汹汹，"+HIG+"便似一条绿色长蛇横卧空际，轻轻摆动，"
                    		+HIR+"颜色又是鲜艳，"+BLU+"又是诡异，光芒闪烁不定"+HIG+"照映得$n头脸皆碧"NOR,
                		"force": 480,
                		"dodge": 20,
                		"weapon": HIG"绿火"NOR,
                		"damage": 90,
                		"damage_type": "烧伤"]); 
        	}
        	
         	if (random(me->query_skill("strike")) > 120 &&
            		me->query("neili") > 400 ) {
                	me->add("neili", -10);
                	return ([
        			"action":HIR"$N突然间双眉往上一竖，右手食指点两点，火焰堆中嗤嗤两声轻响，"+HIG+"爆出几朵火花，犹如流星一般，"
                    		"在$N内力摧迫下，分从左右袭向$n，来势迅速之极"NOR,
                		"force": 450,
                		"dodge": 10,
                		"damage": 90,
                		"weapon": "火花",
                		"damage_type": "烧伤"]);
        	}
    	}
        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_learn(object me)
{
        int  nb,  nh;
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("xingxiu-duzhang", 1);

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练抽髓掌必须空手。\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("你的化功大法火候不够，无法练抽髓掌。\n");
        if ( nb < 100 && nb <= nh )
                return notify_fail("你的毒技修为不够，无法提高抽髓掌。\n");

        if ((int)me->query("max_neili") < 60)
                return notify_fail("你的内力太弱，无法练抽髓掌");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}


int practice_skill(object me)
{
        int  nb,  nh;
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("chousui-zhang", 1);

        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练抽髓掌。\n");
        if ( nb < 100 && nb <= nh )
                return notify_fail("你的毒技修为不够，无法提高抽髓掌。\n");

        if (me->query_skill("chousui-zhang", 1) < 50)
                me->receive_damage("jingli", 20);
        else
                me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int neili, neili2, cases, csz;
        string result;
        neili=me->query("neili");
        neili2=victim->query("neili");
        csz=me->query_skill("chousui-zhang",1);
        
        if(random(neili)>random(neili2)){
                message_vision(MAG"$n猛然觉得一阵寒气袭来，身子一晃，头脑微微有些发昏。\n"NOR, me, victim);
                victim->apply_condition("xx_poison", random(me->query_skill("chousui-zhang", 1)/2) + victim->query_condition("xx_poison"));
                if(victim->query("poisoner") != me) victim->set("poisoner", me);
        } else message_vision(YEL"$n忙运内力抵抗，将$N掌上的剧毒逼在体外。\n"NOR,me,victim);

}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("chousui-zhang", 1) >= 30 )
                return __DIR__"chousui-zhang/" + action;
}
