//Cracked by Roath
// changchun.c

inherit ITEM;

void create()
{
	set_name( "长春经", ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册长春经。\n");
		set("value", 2000);
		set("material", "paper");
		set("skill", ([
			"name":	"beauty",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 10+random(20),// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}
