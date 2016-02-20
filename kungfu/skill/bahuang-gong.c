// bahuang-gong.c 八荒六合唯我独尊功

#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("bahuang-gong", 1);
                mapping skl; 
        string *sname;
        int i, k=0;
        int t = 1, j;
        for (j = 1; j < lvl / 10; j++) t *= 2;
                skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("this_skill") > 99){

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail
("你体内不同内力互相冲撞，难以领会更高深的武功。\n");
        }

        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的八荒六合唯我独尊功。\n");

        if ( me->query("gender") == "男性" && lvl > 120)
                return notify_fail("你身为男子，难以领会高深的八荒六合唯我独尊功。\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("八荒六合唯我独尊功讲究阴阳调合，有违佛家六根清净之意，"
                        +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

        if ((int)me->query_skill("force", 1) < 10 
          || (int)me->query_skill("force", 1)/2 < lvl/3 )
                return notify_fail("你的基本内功火候还不够。\n");

        return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("bahuang-gong", 1) < 150 )
                return notify_fail("你的八荒六合唯我独尊功修为不够，只能用学(learn)的来增加熟练度。\n");
        if ( me->query_temp("weapon") )
                return notify_fail("练习八荒六合唯我独尊功必须空手，静坐诚心方可。\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("你的体力不够练习八荒六合唯我独尊功。\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("你的精力不够练习八荒六合唯我独尊功。\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("你的内力不够练习八荒六合唯我独尊功。\n");

        me->add("neili", -60);
        me->receive_damage("jingli", 60, "精力透支过度死了");
        me->receive_damage("qi", 60, "体力透支过度死了");
        return 1;
}

string exert_function_file(string func)
{
        return __DIR__"bahuang-gong/" + func;
}
