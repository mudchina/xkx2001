//Cracked by Roath
// ding-force.c 小丁气功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("小丁气功只能跟小丁学来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"ding-force/" + func;
}


