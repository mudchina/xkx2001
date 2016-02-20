//Cracked by Roath
// /d/zhongnan/obj/whip_book.c
inherit ITEM;

void create()
{
	set_name("µ¤Ñô±Þ·¨Æ×", ({ "whip book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "±¾");
		set("long",
"¡¸µ¤Ñô±Þ·¨Æ× -- ÉÏ¾í¡¹\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name": 		"whip",		// name of the skill
			"exp_required":	1000,			// minimum combat experience required
											// to learn this skill.
			"jing_cost":		20,				// jing cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	40				// the maximum level you can learn
											// from this object.
		]) );
	}
}
