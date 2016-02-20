//Cracked by Roath
// Lamaism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("lamaism", 1);

	if(me->query("class") != "lama" && lvl > 39)
		return notify_fail("你未入佛门，尘缘不断，无法继续修持密宗神法。\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("密宗心法只能靠学(learn)来提高。\n");
}
