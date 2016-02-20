//Cracked by Roath
//huntian-qigong.c
//modified by Ryu, 1/29/97

inherit FORCE;
#include <ansi.h>
string check() { return "force"; }

#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        mapping skl; 
        string *sname;
	int i, k=0;

        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("huntian-qigong", 1) > 99){

	for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 ) return notify_fail("你体内不同内力互相冲撞，难以领会更高深的内功。\n");
        }


	if ((int)me->query_skill("force", 1) < 10
	  ||(int)me->query_skill("force", 1)/2 < i/3 )
		return notify_fail("你的基本内功火候不足，不能学混天气功。\n");

	return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("huntian-qigong", 1) < 150 )
                return notify_fail("你的混天气功修为不够，只能用学(learn)的来增加熟练度。\n");
        if ( me->query_temp("weapon") )
                return notify_fail("练习混天气功必须空手挥掌运气方可。\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("你的体力不够练习混天气功。\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("你的精力不够练习混天气功。\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("你的内力不够练习混天气功。\n");

	if ( me->query_skill("huntian-qigong", 1) < 250 ) {
        	me->add("neili", -80);
        	me->receive_damage("jingli", 80, "精力透支过度死了");
        	me->receive_damage("qi", 80, "体力透支过度死了");
	}
	else {
		me->add("neili", -100);
                me->receive_damage("jingli", 100, "精力透支过度死了");
                me->receive_damage("qi", 100, "体力透支过度死了");
	}

        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"huntian-qigong/" + func;
}

mapping curing_msg(object me)
{
	return ([
		"start_self"	: HIW+BLK"你缓缓坐起身来调匀呼吸，将混天功真气流遍全身。\n"NOR,
		"start_other"	: HIW+BLK+ me->name() +"坐起身来，头顶立时冒出热气，额头汗如雨下，全身颤抖不已。\n"NOR,
		"finish_other"	: WHT"但见"+ me->name() +"脸上一阵红潮涌上，便即退去，又成灰白，这般红变白，白变红的转了数次。\n"NOR,
		"unfinish_other": HIW+BLK+ me->name() +"眼睛慢慢睁开一线，吐了一滩黑血。\n"NOR,
	]);
}