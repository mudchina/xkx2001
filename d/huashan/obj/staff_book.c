//Cracked by Roath
// staff_book.c 棍法图解
inherit ITEM;

void create()
{
	set_name("杖法图解", ({ "staff book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本线装书，里面密密麻麻的画了不少舞杖的姿势。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"staff",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
