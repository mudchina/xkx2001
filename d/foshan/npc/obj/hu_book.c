//Cracked by Roath
// sword_book.c

inherit ITEM;
void create()
{
	set_name("胡家刀法残篇", ({ "hujia daofa", "book", "daofa" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
		"这是胡一刀根据明末大侠飞天狐狸所创刀法改进的「胡家刀法」的前两页，上面讲了些刀法的入门知识。\n");
		set("value", 100);
		set("material", "paper");
		set("no_sell", 1);
		set("skill", ([
			"name": 		"blade",		// name of the skill
			"exp_required":	1000,			// minimum combat experience required
											// to learn this skill.
			"jing_cost":		30,				// jing cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	40				// the maximum level you can learn
											// from this object.
		]) );
	}
}
