//Cracked by Roath
// ziyin_book2.c

inherit ITEM;

void create()
{
	set_name("×Ïë³Ò÷¾÷Æ×ÏÂ¾í", ({ "ziyin book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "±¾");
		set("long","×Ïë³Ò÷ÊÇ»ªÉ½ÅÉÁ·¾«µÄ¸è¾÷¡£\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":		"ziyin-yin",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	40,			// jing cost every time study this
			"difficulty":	20,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	100			// the maximum level you can learn
								// from this object.
		]) );
	}
}
