//Cracked by Roath

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl, lvl2;
	
	lvl = (int)me->query_skill("qimen-dunjia", 1);
	lvl2 = (int)me->query_skill("literate", 1);


	if ( lvl > lvl2 && (lvl-lvl2) > 100)
		return notify_fail("奇门遁甲对你来说太深奥了。\n");


	if ( lvl > 100 && me->query_int()-15 < lvl/10 )
		return notify_fail("奇门遁甲对你来说太深奥了。\n");

	if ( lvl > 100 && me->query("qmdj_use")*10 < lvl-100 )
		return notify_fail("你在奇门遁甲上的应用不足，难以继续领会。\n");
	return 1;
}

int practice_skill(object me)
{       
	return notify_fail("奇门遁甲只能靠学(learn)来提高。\n");
}
