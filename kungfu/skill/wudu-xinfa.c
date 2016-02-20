// wudu-xinfa 五毒心法
// By Xuanyuan
#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("wudu-xinfa", 1);
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
                return notify_fail("你无根无性，阴阳不调，难以领会高深的五毒心法。\n");

        if ( me->query("gender") == "男性" && lvl > 80)
                return notify_fail("你身为男子，难以领会高深的五毒心法。\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("五毒心法讲究阴阳调合，有违佛家六根清净之意，"
                        +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

        if ((int)me->query_skill("force", 1) < 10 
          || (int)me->query_skill("force", 1)/2 < lvl/3 )
                return notify_fail("你的基本内功火候还不够。\n");

        if (lvl > 10 && (int)me->query("shen") > - t * 100
             && me->query_skill("yunu-jue", 1) < 100) 
                return notify_fail("修习五毒心法要心狠手辣，你做的还不够。\n");

        return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("wudu-xinfa", 1) < 150 )
                return notify_fail("你的五毒心法修为不够，只能用学(learn)的来增加熟练度。\n");
        if ( me->query_temp("weapon") )
                return notify_fail("练习五毒心法必须空手，静坐诚心方可。\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("你的体力不够练习五毒心法。\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("你的精力不够练习五毒心法。\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("你的内力不够练习五毒心法。\n");

        me->add("neili", -60);
        me->receive_damage("jingli", 60, "精力透支过度死了");
        me->receive_damage("qi", 60, "体力透支过度死了");
        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"wudu-xinfa/" + func;
}

mapping curing_msg(object me)
{
	return ([
		"apply_short"	: me->name() +"坐在一旁垂帘入定，头顶笼罩"HIB"淡蓝色的雾气"NOR"。",
		"start_self"	: HIW"你调息凝精，默运内功开始运功疗伤。\n"NOR,
		"start_other"	: HIW"只见"+ me->name() +"闭目坐下，片刻之时，头顶冒出丝丝淡蓝色的雾气\n"NOR,
		"finish_self"	: HIY"过了一会，雾气消去，你看起来脸色好多了。\n"NOR,
		"finish_other"	: me->name() +"惨白的脸色渐渐红润，缓缓睁开眼，站起身来。\n",
		"unfinish_self" : "你渐感真气不纯，后劲不继，不得不将在体内搬运的内息收回。\n",
		"unfinish_other": me->query("eff_qi") < me->query("max_qi")*3/4 ?
				  "猛地里"+ me->name() +"口一张，喷出几口鲜血。\n" :
				  "猛地里"+ me->name() +"口一张，吐出口紫黑瘀血。\n",
	]);
}