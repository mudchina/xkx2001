//Cracked by Kafei
// ziyin_book1.c

inherit ITEM;

void create()
{
	set_name("玉女二十四诀上卷", ({ "yunu book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","玉女二十四诀是古墓派修身练精的心法要诀。十二少正诀：\n"
			   "少思、少念、少欲、少事、少语、少笑、少愁、少乐、少喜、\n"
			   "少怒、少好、少恶。行此十二少，乃养生之都契也。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"yunu-jue",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	20,			// jing cost every time study this
			"difficulty":	10,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	60			// the maximum level you can learn
								// from this object.
		]) );
	}
}
