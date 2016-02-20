//Cracked by Roath
// kick.c

#include <ansi.h>

inherit SKILL;

int valid_learn() { return 1; }

string exert_function_file(string func)
{
	return "/kungfu/skill/kick/" + func;
}

void skill_improved(object me)
{}
