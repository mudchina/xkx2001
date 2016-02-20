//Cracked by Roath
// wuji1.c

inherit ITEM;

string* titles = ({
        "罗汉拳法",
        "风云手手法",
        "般若掌法",
        "普渡杖法",
        "伏魔剑法",
        "达摩剑法",
});

string* skills = ({
        "luohan-quan",
	"fengyun-shou",
        "banruo-zhang",
        "pudu-zhang",
        "fumo-jian",
        "damo-jian",
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
			"jing_cost": 40,// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
			"max_skill":	99	// the maximum level you can learn
		      ]) );
}
