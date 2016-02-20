//Cracked by Roath
// zixia-shengong.c 华山 紫霞功
// qfy July 4, 1996.

inherit FORCE;
string check() { return "force"; }

#include <ansi.h>
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	        mapping skl; 
        string *sname;
        int v, k=0;
        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("zixia-gong", 1) > 99){

       for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail("你体内不同内力互相冲撞，难以领会更高深的内功。\n");
        }

	if ( (int)me->query_skill("force", 1)  <  10 
	   ||(int)me->query_skill("force", 1)/2 < (int)me->query_skill("zixia-gong", 1)/3 )
		return notify_fail("你的基本内功火候还不够，无法领会紫霞功。\n");

	if ( me->query("gender") == "无性" && (int)me->query_skill("zixia-gong",1) > 49)
		return notify_fail("公公无根无性，紫霞功再难更上一层楼。\n");

	if ( (int)me->query_skill("zixia-gong", 1) >= 45 
	&& (int)me->query_skill("huagong-dafa", 1) >= 100
	&& (int)me->query_int() < 40 )
		return notify_fail("你受高深的邪派内功牵绊，与紫霞功水火难容，再难更上一层楼。\n");

	return 1;
}

int practice_skill(object me)
{
	if ( me->query_skill("zixia-gong", 1) < 150 )
		return notify_fail("你的紫霞功修为不够，只能用学(learn)的来增加熟练度。\n");
	if ( !present("zixia book", me) )
		return notify_fail("你无凭无据，如何练习紫霞功？\n");
	if ( me->query_temp("weapon") )
		return notify_fail("练习紫霞功必须空手，静坐诚心方可。\n");
	if ( (int)me->query("qi") < 70 )
		return notify_fail("你的体力不够练习紫霞功。\n");
	if ( (int)me->query("jingli") < 70 )
		return notify_fail("你的精力不够练习紫霞功。\n");
	if ( (int)me->query("neili") < 70 )
		return notify_fail("你的内力不够练习紫霞功。\n");

	me->add("neili", -60);
	me->receive_damage("jingli", 60, "精力透支过度死了");
	me->receive_damage("qi", 60, "体力透支过度死了");
        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"zixia-gong/" + func;
}

mapping curing_msg(object me)
{
	return ([
		"start_self"	: MAG"你就地盘坐，运使紫霞神功疗伤，内息返诸柔善，鸣天鼓，饮玉浆，荡华池，叩金梁，流通周身脉络。\n"NOR,
		"start_other"	: MAG+me->name()+ "就地盘坐，脸现紫气，开始运功疗伤。\n"NOR,
		"finish_self"	: "你催运紫霞功疗伤多时，一道真气在体内运转无碍，内伤已经平复，当即站起身来。\n",
		"finish_other"	: MAG"但见"+ me->name()+ "头顶白雾弥漫，脸上紫气大盛，忽然间一声长啸，站起身来。\n"NOR,
	]);
}
