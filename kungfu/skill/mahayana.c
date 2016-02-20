//Cracked by Roath
// mahayana.c 大乘涅磐法

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl, lvl2;
	
	lvl = (int)me->query_skill("mahayana", 1);
	lvl2= (int)me->query_skill("persuading", 1);

	if( (lvl >= 60 && lvl2 <= lvl && lvl2 < 150) || lvl2 <= lvl/2 )
		return notify_fail("大乘佛教崇尚普渡众生，你须多多渡世济人才能继续提高大乘涅磐法修为。\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("大乘涅磐法只能靠学(learn)来提高。\n");
}
