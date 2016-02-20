//Cracked by Roath
// tianji-xuangong.c 桃花 天机玄功
// Ryu

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i, nb, nf, nh;
	nb = (int)me->query_skill("qimen-dunjia", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("tianji-xuangong", 1);

	if ( nb < 120 && nb <= nh )
		return notify_fail("你的奇门遁甲修为不够，无法领会更高深的天机玄功。\n");

	if ( nf < 10 || nf/2 < nh/3 )
		return notify_fail("你的基本内功火候还不够，无法领会天机玄功。\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("天机玄功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"tianji-xuangong/" + func;
}
