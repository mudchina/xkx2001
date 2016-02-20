//Cracked by Roath
// necromancy.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="spell"; }

int valid_learn(object me)
{
if( (int)me->query_skill("medicine") < (int)me->query_skill("cursing")*2/3 )
return notify_fail("你的基本医理修为不够，无法领悟更高深的降头术。\n");
	return 1;
}

string cast_spell_file(string spell)
{
	return __DIR__"cursing/" + spell;
}


int practice_skill(object me)
{	
return notify_fail("降头术只能通过读书来提高。\n");
}

int learn_skill(object me)
{
return notify_fail("降头术只能通过读书来提高。\n");
}

