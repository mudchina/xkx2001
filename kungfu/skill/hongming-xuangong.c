//Cracked by Roath
//hongming-xuangong.c 鸿冥玄功
// snowbird august 1999
// 1.1.1.1

#include <ansi.h>

inherit FORCE;
#include "/kungfu/skill/force_list.h"

string check() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	mapping skl; 
	string *sname;
	int i, k=0, nb, nk, lvl = (int)me->query_skill("hongming-xuangong", 1);

	skl=this_player()->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );

	if (me->query_skill("this_skill") > 99) {
        for(i=0; i<sizeof(skl); i++)
			if (SKILL_D(sname[i])->check() == "force") k++;
		if (k >=2) return notify_fail ("你体内不同内力互相冲撞，难以领会更高深的武功。\n");
	}

	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候还不够。\n");

	return 1;
}

int practice_skill(object me)
{
	if ( me->query_skill("kurong-changong", 1) < 150 )
		return notify_fail("你的鸿冥玄功修为不够，只能用学(learn)的来增加熟练度。\n");
	if ( me->query_temp("weapon") )
		return notify_fail("修行鸿冥玄功必须空手。\n");
	if ( (int)me->query("jing") < 110 )
		return notify_fail("你的精神不好，无法练习鸿冥玄功。\n");
	if ( (int)me->query("jing") < 60 )
		return notify_fail("你的精力不够练习鸿冥玄功。\n");
	if ( (int)me->query("neili") < 110 )
		return notify_fail("你的内力不够练习鸿冥玄功。\n");

	me->add("neili", -100);
	me->receive_damage("jingli", 50, "精力透支过度死了");
	me->receive_damage("jing", 100, "精力透支过度死了");

        return 1;
}


string exert_function_file(string func)
{
	return __DIR__"hongming-xuangong/" + func;
}
