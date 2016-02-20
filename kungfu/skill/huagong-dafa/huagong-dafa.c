//Cracked by Roath
// huagong-dafa.c 化功大法
// by yucao
// modified by cleansword

#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("huagong-dafa", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10
          ||(int)me->query_skill("force", 1)/2 < i/3 )
                return notify_fail("你的基本内功火候不足，不能学化功大法。\n");
        if (i > 10 && i < 200 && (int)me->query("shen") > t * 100)
                return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");
        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1)
          || me->query_skill("mahayana",1) || me->query_skill("lamaism", 1))
                return notify_fail("你练了秃驴牛鼻子们的心法，还学化功大法做什戚！\n");
        if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("linji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("longxiang-banruo", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)    
        || me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1)
        || me->query_skill("bitao-xuangong", 1) )
                return notify_fail("你不先散了别派内功，怎能学化功大法？！\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("化功大法只能用学(learn)的来增加熟练度。\n");
}


mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

	if ((int)victim->query_temp("hua")!=1) return damage;
	
	dp = (int)victim->query_skill("huagong-dafa",1);

        if (objectp(weapon2) ){
                dp += victim->query_skill("tianshan-zhang",1);
        } else if (!objectp(weapon2) ) {
                if ( victim->query_skill_prepared("strike") != "chousui-zhang"  || victim->query_skill_prepared("claw") != "sanyin-zhua")
                        return damage;
                dp += victim->query_skill("chousui-zhang",1);
        } else return damage;

        ap = me->query_skill("force",1);
        if (objectp(weapon1))
                ap += me->query_skill("dodge");
        else
                ap *= 2;

        if ( random(ap+dp) > ap ) {
                if ( objectp(weapon2) && objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
		                me->add("neili", -victim->query_skill("huagong-dafa",1)/3*2);
				victim->add("neili", victim->query_skill("huagong-dafa",1)/3*2);
                                result = HIB"$n将化功大法运到杖上，和$N的兵刃相交，$N突然觉得内力源源不绝从的流了出去。\n"NOR;
                        }
                        else result = HIB"只见$n手中杖发出淡淡蓝光，$N心中一惊，不敢妄进，将兵刃收了回去。\n"NOR;
                }
                else if(objectp(weapon2) && !objectp(weapon1)){
                        if (damage + damage_bonus > 0)
			{
			        result = HIB"$n化功大法自然而然发动，$N突然觉得内力源源不绝从的流了出去。\n"NOR;                      
                                me->add("neili", (-victim->query_skill("huagong-dafa",1)-me->query("jiali"))/3*2);
	            		victim->add("neili", victim->query_skill("huagong-dafa",1)/3*2);
			}
                	else result = HIB"只见$n嘴角微微冷笑，似乎成竹在兄，$N心中一惊，不敢妄进，将进招改为守招。\n"NOR;
		}
        	else if( !objectp(weapon2) && objectp(weapon1) ) {
                        if (damage + damage_bonus > 0)
                        {                 
		                me->add("neili", -victim->query_skill("huagong-dafa",1)/3*2);
				victim->add("neili", victim->query_skill("huagong-dafa",1)/3*2);
                                result = HIB"$n将身子一側，顺手把$N的兵刃一带，$N突然觉得胸中若有所失。\n"NOR;
                        }
                        else result = HIB"只见$n嘿嘿一笑，竟然不招不架，$N心中一惊，不敢妄进，将兵刃收了回去。\n"NOR;
                }
                else{
                        if (damage + damage_bonus > 0)
                        {                 
		                me->add("neili", -victim->query_skill("huagong-dafa",1)/3*2);
				victim->add("neili", victim->query_skill("huagong-dafa",1)/3*2);
                                result = HIB"$N的手掌和$n的身体一触，觉得内力飞快的流了出去。\n"NOR;
                        }
                        else result = HIB"只见$n嘿嘿一笑，竟然不招不架，$N心中一惊，不敢妄进，将兵刃收了回去。\n"NOR;
                }
	}
        return ([ "result" : result, "damage" : damage_bonus ]);
}


string exert_function_file(string func)
{
        mapping skl;
        string *sname;
        int v, k=0;

        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;
        }
        if ( k >=2 ){
        tell_object(this_player(), "你体内不同内力互相冲撞，难以施展化功大法。\n");
        return 0;
        }

        return __DIR__"huagong-dafa/" + func;
}
