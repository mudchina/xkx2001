//Cracked by Roath
// xiaoao-jianfa.c 逍遥剑法
//无约无束，自由自在，随心所欲，豪放不羁，心如山水，志比霞烟，日月入怀，逍遥云天。

#include <combat.h>
#include <ansi.h>

inherit SKILL;
mapping *action = ({
([      "action" : "$N$w随意轻挑，一式「无约无束」，$w毫无章法地抖出几点金星，时隐时现地飘向$n",
        "force" : 170,
        "dodge" : 15,
        "parry" : 15,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "无约无束",
        "damage_type" : "刺伤"
]),
([      "action" : "$N行似流水，动似浮云，衣袖微扬，递出一招「自由自在」，$w锋划向$n的$l",
        "force" : 210,
        "dodge" : 25,
        "parry" : 15,
        "damage": 30,
        "lvl" : 15,
        "skill_name" : "自由自在",
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w一闪而出，正是一招「随心所欲」，心意所指，剑光即至，几经变换终不离$n的$l",
        "force" : 270,
        "dodge" : 25,
        "parry" : 20,
        "damage": 55,
        "lvl" : 30,
        "skill_name" : "随心所欲",
        "damage_type" : "刺伤"
]),
([      "action" : "一改剑法之飘逸，$N真气布满全身，将$w舞得大开大和，脚踏中宫，一式「豪放不羁」，$w带着风声朝$n的$l劈去。",
        "force" : 340,
        "dodge" : 20,
        "parry" : 20,
        "damage": 60,
        "lvl" : 40,
        "skill_name" : "豪放不羁",
        "damage_type" : "劈伤"
]),
([      "action" : "$N$w轻挥，一招「心如山水」泱出几层剑浪，翻江捣海一般涌向$n",
        "force" : 380,
        "dodge" : 20,
        "parry" : 20,
        "damage": 70,
        "lvl" : 55,
        "skill_name" : "心如山水",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「志比霞烟」，身行飘忽不定，$w现出一片霞光，裹住$N，身剑合一，飞向$n",
        "force" : 400,
        "dodge" : 30,
        "parry" : 20,
        "damage": 80,
        "lvl" : 65,
        "skill_name" : "志比霞烟",
        "damage_type" : "割伤"
]),
([      "action" : "$N左手剑决朝$n一引，$w化一招「日月入怀」，剑尖划出一大一小两个圆圈，拢向$n周身上下",
        "force" : 430,
        "dodge" : 20,
        "parry" : 30,
        "damage": 85,
        "lvl" : 75,
        "skill_name" : "日月入怀",
        "damage_type" : "割伤"
]),
([      "action" : "$N身行高纵，一招「逍遥云天」从上递出，$w幻为数十点银芒，恍恍惚惚，飘落向$n",
        "force" : 450,
        "dodge" : 30,
        "parry" : 30,
        "damage": 95,
        "lvl" : 85,
        "skill_name" : "逍遥云天",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenghuo-xuangong",1) < 20)
                return notify_fail("你的圣火玄冥功火候未到，暂无法修习逍遥剑法。\n");
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
        level   = (int) me->query_skill("xiaoyao-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
        
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够修练逍遥剑法。\n");
        me->receive_damage("jingli", 30, "精力透支过度死了");
        return 1;
}


mixed hit_ob(object me, object victim, int damage)
{
        string msg;
        int ap, dp, zhencost,skill;
        string result;
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon")))
                return 0;
        
        skill=me->query_skill("xiaoyao-jianfa",1);
        ap = me->query("combat_exp")/1000;
        ap += me->query_skill("sword");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("dodge");
        ap = (ap + random(ap*2))/2;
        
        if(me->query_temp("xiaoyao")) {
	        if ( random(ap+dp) > ap ) {
        	        result = HIG "\n$N身形飘忽不定，左手握了一个剑决，身子滴溜溜地一转，已经欺到$n身前，唰地一剑。\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*4-skill*2);
        	        victim->start_busy(1+random(2));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else if ( random(ap+dp) > ap ) {
                	result = HIG "\n$N身形飘起，长啸一声，手中"+(string)weapon->query("name")+HIG"猛地刺向$n。\n" NOR;
                	message_vision(result,me,victim);
	       	        victim->add("qi", -weapon->query("weapon_prop/damage")*5-skill*5/2);
        	        victim->start_busy(1+random(3));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else if ( random(ap+2*dp) > ap ) {
                	result = HIG "\n$N左一剑，右一剑，剑剑不离$n的要害，突然中宫直进，直取$n的胸膛。\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*6-skill*3);
        	        victim->start_busy(1+random(4));
                	damage = 0;

                	return ([ "result" : result, "damage" : damage ]);
        	}
        	else
        	{
                	result = HIG"\n但见"+weapon->name()+HIG"一闪，剑间已到$n身前，$n不由地手足无措。\n" NOR;
                	message_vision(result,me,victim);
	                victim->add("qi", -weapon->query("weapon_prop/damage")*3-skill*3/2);
        	        victim->start_busy(1+random(2));
	                damage = 0;
        
                	return ([ "result" : result, "damage" : damage ]);
        	}
     	}
}


mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

        if ((int)victim->query_temp("xiaoyao")!=1) return damage;
        
        dp = (int)victim->query_skill("force",1);

        dp += victim->query_skill("xiaoyao-jianfa",1);
        
        ap = me->query_skill("force",1);
        if (objectp(weapon1))
                ap += me->query_skill("dodge");
        else
                ap *= 2;

        if ( random(ap+dp) > ap ) {
                
                if ( objectp(weapon2) && objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
                                victim->add("neili", -victim->query_skill("force",1)/3*2);
                                damage_bonus=-random(4000);
                                result = HIW"$n剑法一变，转为守势，剑尖划出一个个圆圈，$N心中一动，放缓了攻击。\n"NOR;
                        }
                }
                
                else if(objectp(weapon2) && !objectp(weapon1)){
                        if (damage + damage_bonus > 0)
                        {
                                damage_bonus=-random(4000);
                                result = HIW"$n微微一笑，剑尖颤动，直指$N手腕，$N只得向后跃开。\n"NOR;                      
                                me->add("neili", (-victim->query_skill("force",1)-me->query("jiali"))/3*2);
                        }

                } else{
                        if (damage + damage_bonus > 0)
                        {                 
                                victim->add("neili", -victim->query_skill("force",1)/3*2);
                                damage_bonus=-random(4000);
                                result = HIW"$n剑法一变，转为守势，剑尖划出一个个圆圈，$N心中一动，放缓了攻击。\n"NOR;
                        }                                
                }
        }
        return ([ "result" : result, "damage" : damage_bonus ]);
}






string perform_action_file(string action)
{
        return __DIR__"xiaoyao-jianfa/" + action;
}


