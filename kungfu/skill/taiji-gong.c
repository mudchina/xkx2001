//Cracked by Roath
// taiji-gong.c 太极功
// xQin 2/00

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( me->query_skill("taiji-gong") < 10 || me->query_skill("taiji-jian") < 50
		|| me->query_skill("taiji-quan") < 50 )
		return notify_fail("你现在还不能学习太极系的功夫。\n");

	return 1;
}
