//Cracked by Roath
// fojing1.c

inherit ITEM;

string* titles = ({
	"般若经",
	"维摩经",
	"法华经",
	"华严经",
//	"无量寿经",
//	"大般涅磐经",
//	"阿含经",
//	"金刚经",
//	"波罗蜜多心经",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "fo jing", "jing", "shu" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册佛经。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"buddhism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}
