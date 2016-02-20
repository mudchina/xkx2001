//Cracked by Roath
// zhengqi_book.c

inherit ITEM;

void create()
{
	set_name("正气诀诀谱下卷", ({ "zhengqi book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","正气诀是华山派练气的心法。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"zhengqi-jue",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	30+random(30),		// jing cost every time study this
			"difficulty":	25,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	100			// the maximum level you can learn
								// from this object.
		]) );
	}
}
