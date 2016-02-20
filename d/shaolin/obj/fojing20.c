//Cracked by Roath
//权宜限制：读心法至400 lv祗限于超级高手，否则对其他门派不公平。 //by maco
// fojing20.c

inherit ITEM;

string* titles = ({
//	"般若经",
//	"维摩经",
//	"法华经",
//	"华严经",
	"无量寿经",
	"大般涅磐经",
	"阿含经",
	"金刚经",
	"波罗蜜多心经",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册佛经。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"buddhism",	// name of the skill
			"exp_required":	4000000,	// minimum combat experience required
			"jing_cost":	40,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	400	// the maximum level you can learn
		]) );
	}
}
