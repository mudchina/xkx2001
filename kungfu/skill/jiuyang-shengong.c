//Cracked by Roath
// jiuyang-shengong 九阳神功
// by wsky


#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("jiuyang-shengong", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;

        if ((int)me->query_skill("force", 1) < 10
          ||(int)me->query_skill("force", 1)/2 < i/3 )
                return notify_fail("你的基本内功火候不足，不能学习九阳神功。\n");

        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1)
          || me->query_skill("mahayana",1) || me->query_skill("lamaism", 1))
                return notify_fail("你练了秃驴牛鼻子们的心法，还学化功大法做什戚！\n");

        if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("linji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("longxiang-banruo", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)    
        || me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1)
        || me->query_skill("bitao-xuangong", 1) || me->query_skill("hamagong", 1) )
                return notify_fail("你不先散了别派内功，怎能学化功大法？！\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("九阳神功只能靠领悟《九阳真经》来增加熟练度。\n");
}


mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

	dp = (int)victim->query_skill("jiuyang-shengong",1)+(int)victim->query_skill("parry",1);

        ap = me->query_skill("force",1);
        if (objectp(weapon1))
                ap += me->query_skill("dodge");
        else
                ap *= 2;

        if ( random(ap+dp) > ap ) {
                if ( objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
				damage_bonus=-random(4000);
                                result = HIM"$n身子一侧，将$N兵刃上的力道卸去大半。\n"NOR;
                        }
                        else {
				result = MAG"$n身子一侧，将$N兵刃上的力道卸去大半。\n"NOR;
				damage_bonus=-random(4000);
			}
                }
                else if(!objectp(weapon1)){
                        if (damage + damage_bonus > 0)
			{
				damage_bonus=-random(4000);
			        result = HIG"$n九阳神功自然而然发出抗力，将$N的力道一挡。\n"NOR;                      
			}
                	else {
				result = MAG"$n九阳神功自然而然发出抗力，将$N的力道一挡。\n"NOR;
				damage_bonus=-random(4000);
			}
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
        if ( k >=2 && this_player()->query("id")!="wsky"){
        tell_object(this_player(), "你体内不同内力互相冲撞，难以施展九阳神功。\n");
        return 0;
        }

        return __DIR__"jiuyang-shengong/" + func;
}
