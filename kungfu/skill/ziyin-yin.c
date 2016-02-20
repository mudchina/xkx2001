//Cracked by Roath
// ziyin-yin.c 紫氤吟

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("shen") < 0 )
		return notify_fail("你的邪气太重，无法修炼华山紫氤吟。\n");
		
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("华山紫氤吟只能靠学习来提高。\n");
}
