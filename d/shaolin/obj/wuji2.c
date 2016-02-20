//Cracked by Roath
// wuji2.c

inherit ITEM;

string* titles = ({
        "如来千叶手手法",
        "大金刚拳法",
        "无常杖法",
        "慈悲刀法",
        "修罗刀法",
        "醉棍棍法",
});

string* skills = ({
        "qianye-shou",
        "jingang-quan",
        "wuchang-zhang",
        "cibei-dao",
        "xiuluo-dao",
        "zui-gun",
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
			"max_skill":	299	// the maximum level you can learn
		      ]) );
}
