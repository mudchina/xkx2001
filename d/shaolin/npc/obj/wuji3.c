//Cracked by Roath
// wuji13.c

inherit ITEM;

string* titles = ({
        "散花掌法",
        "拈花指法",
        "韦陀棍法",
        "鹰爪功法",
        "龙爪功法",
        "一指禅功",
});

string* skills = ({
        "sanhua-zhang",
        "nianhua-zhi",
	"weituo-gun",
        "yingzhua-gong",
        "longzhua-gong",
        "yizhi-chan",
});

void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "shaolin wuji", "wuji" }));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册" + titles[i] + "\n");
	set("value", 200);
	set("material", "paper");
	set("skill", ([
			"name":	skills[i],	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost":  40,// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
			"max_skill":	99	// the maximum level you can learn
		      ]) );
}
