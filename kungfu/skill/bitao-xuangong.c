//Cracked by Roath
// bitao-xuangong.c 碧涛玄功
// kane May 4, 1997.

#include <ansi.h>
inherit FORCE;
#include "/kungfu/skill/force_list.h"

string check() { return "force"; }

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
        mapping skl; 
        string *sname;
        int i, k=0;

        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("baitao-xuangong", 1) > 99){

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 )return notify_fail ("你体内不同内力互相冲撞，难以领会更高深的内功。\n");
        }


	if ( (int)me->query_skill("force", 1)  <  10 
	   ||(int)me->query_skill("force", 1)/2 < (int)me->query_skill("bitao-xuangong", 1)/3 )
		return notify_fail("你的基本内功火候还不够，无法领会碧涛玄功。\n");

	if ( me->query("gender") == "无性" && (int)me->query_skill("bitao-xuangong",1) > 59)
		return notify_fail("公公无根无性，碧涛玄功再难更上一层楼。\n");

	if ( (int)me->query_skill("bitao-xuangong", 1) >= 45 
	&& (int)me->query_skill("huagong-dafa", 1) >= 100
	&& (int)me->query_int() < 40 )
		return notify_fail("你受高深的邪派内功牵绊，与碧涛玄功水火难容，再难更上一层楼。\n");

	if ( (int)me->query_skill("bitao-xuangong", 1) >= 120 
	&& (int)me->query_skill("huagong-dafa", 1) >= 1 
	&& (int)me->query_int() < 40 )
		return notify_fail("你身负邪派内功，与碧涛玄功水火难容，再难更上一层楼。\n");


	return 1;
}

int practice_skill(object me)
{
	if ( me->query_skill("bitao-xuangong", 1) < 180 )
		return notify_fail("你的碧涛玄功修为不够，只能用学(learn)的来增加熟练度。\n");
	if ( me->query_temp("weapon") )
		return notify_fail("练习碧涛玄功必须空手，静坐诚心方可。\n");
	if ( (int)me->query("qi") < 70 )
		return notify_fail("你的体力不够练习碧涛玄功。\n");
	if ( (int)me->query("jingli") < 70 )
		return notify_fail("你的精力不够练习碧涛玄功。\n");
	if ( (int)me->query("neili") < 70 )
		return notify_fail("你的内力不够练习碧涛玄功。\n");
	if ( (int)me->query("potential") < 1)
                return notify_fail("你的潜能不够！\n");

	me->add("neili", -36);
	me->receive_damage("jingli", 49, "精力透支过度死了");
	me->receive_damage("qi", 49, "体力透支过度死了");
        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"bitao-xuangong/" + func;
}

// move to luoying-shenfa
/*
mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
	string msg;
	int ap, dp;


	if( !victim->query_temp("wuzhuan") ) return damage;
	
	if( !victim->is_busy() ) return damage;

	ap = me->query("combat_exp")/1000;
	dp = victim->query("combat_exp")/1000;
	dp += victim->query_skill("bitao-xuangong", 1);
	dp += victim->query_skill("qimen-dunjia", 1);
	dp = (dp + random(dp*2))/2;

	if( ap > dp ) return damage;

        victim->start_busy(1);
        victim->interrupt_me();
	msg = HIB "$N一声长啸，脚下踩着奇门步法，趋前抢后，尤如天神行法，";
        msg += "鬼魅遁影，瞬间只见数十个身影飞射而出，游走不定！\n"NOR;
        
	message_vision(msg, victim);
	return damage;
}

*/

mapping curing_msg(object me)
{
        return ([
"apply_short"	:me->name()+"正踏著八卦方位缓步行走疗伤。",
"start_self"	:HIG"你脚下缓缓踏著八卦方位，步法暗合五行九宫，一边潜运碧涛玄功调理伤势。\n"NOR,
"start_other"	:HIG""+me->name()+"缓步走动，呼吸由急促渐渐转而悠长，面上青气时隐时现。\n"NOR,
"finish_self"	:HIG"你缓步行走多时，自觉经脉顺畅，内伤尽去，在东方乙木之位停下了步伐。\n"NOR,
"finish_other"	:me->name()+"疗伤已毕，脸上青气一闪而退，停下脚步，看上去气色饱满，精神抖擞。\n",
"unfinish_self"	:"你正以奇门步法调匀真气，忽觉内息後继乏力，祗得停下脚步，暂缓疗伤。\n",
"unfinish_other":me->name()+"停下脚步，脸上青气隐退，气色看起来好多了。\n",
"halt_self"	:"你吐气纳息，硬生生地将内息压了下去，停下了脚步。\n",
"halt_other"	:me->name() +"缓缓停下步伐，身子一震，吐出一口瘀血，脸上青气随之散逸。\n",

        ]);
}
