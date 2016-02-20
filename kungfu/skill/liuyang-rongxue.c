//Cracked by Roath
//liuyang-rongxue.c 六阳融雪功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("liuyang-rongxue", 1);

	if ( me->query("gender") == "无性" )
		return notify_fail("六阳融雪功是调练那天生的一股纯阳罡气，你无根无性怎会懂得其中之奥妙。\n");

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的六阳融雪功。\n");

        if ( me->query("gender") == "女性" && lvl > 99)
                return notify_fail("你基与先天体质所限，难以领会高深的六阳融雪功。\n");

	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候还不够。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("六阳融雪功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}

