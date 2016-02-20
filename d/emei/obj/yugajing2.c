//Cracked by Roath
// yugajing0.c

inherit ITEM;

string* titles = ({
//	"法华经",
//	"华严经",
//	"楞严经",
//	"般若经",
	"般若波罗密多心经",
	"大般涅磐经",
	"金刚经",
	"大弥陀经",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "maha jing", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册大乘佛经。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"mahayana",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	40,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
		]) );
	}
}
