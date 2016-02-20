//Cracked by Roath
// yiwei-dujiang.c 一苇渡江

inherit SKILL;

int valid_learn(object me)
{
	mapping fam;
	object weapon;

	fam = me->query("family"); 
	if( !mapp(fam) || fam["family_name"] != "少林派" )
		return notify_fail("你不属于少林派，不能学习一苇渡江功！\n");

	if ( fam["family_name"] == "少林派" && fam["generation"] != 35 )
		return notify_fail("你资格不够，不能学习一苇渡江，等到升了渡字辈再说吧。\n");

	return 1;
}

