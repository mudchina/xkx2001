//Cracked by Roath
// medicine.c 药理学

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}


int valid_learn(object me)
{
        if( !me->query_temp("mark/陆") )
                return notify_fail("你现在不能学习药理学。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("药理学得靠学(learn)来提高。\n");
}

/*
string perform_action_file(string action)
{
	return __DIR__"medicine/" + action;
}
*/

