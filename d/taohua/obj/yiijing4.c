//Cracked by Roath
// yijing.c

inherit ITEM;

void create()
{
	set_name( "易经《系辞篇》", ({ "jing", "yi jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册易经。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"qimen-dunjia",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 40, 	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	120,	// the maximum level you can learn
		]) );
	}
}
