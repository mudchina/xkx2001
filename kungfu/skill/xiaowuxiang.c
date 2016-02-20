//Cracked by Roath
// qfy July 4, 1996.

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	if( me->query("family/family_name") != "逍遥派")
                return notify_fail("你不能学小无相功。\n");

	if ( (int)me->query_skill("force", 1)  <  10 )
		return notify_fail("你的基本内功火候还不够，无法领会龙象般若功。\n");

	if ( me->query("gender") == "无性" && (int)me->query_skill("xiaowuxiang",1) > 49)
		return notify_fail("公公无根无性，小无相功再难更上一层楼。\n");

	if ( (int)me->query_skill("xiaowuxiang", 1) >= 45 
	&& (int)me->query_skill("huagong-dafa", 1) >= 100
	&& (int)me->query_int() < 40 )
		return notify_fail("你受高深的邪派内功牵绊，小无相功再难更上一层楼。\n");

	if ( (int)me->query_skill("xiaowuxiang", 1) >= 110 
	&& (int)me->query_skill("huagong-dafa", 1) >= 1 
	&& (int)me->query_int() < 40 )
		return notify_fail("你身负邪派内功，小无相功再难更上一层楼。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("小无相功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiaowuxiang/" + func;
}
