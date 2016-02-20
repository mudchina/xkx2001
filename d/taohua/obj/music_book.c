//Cracked by Roath
//music book

inherit ITEM;


string* names = ({
        "《乐府古题要解》",
        "《乐书要录》",
        "《敦煌曲谱》",
        "《风雅十二诗谱》",
});
string* longs = ({
        "音乐著录，唐代吴兢撰，记有许多乐曲的命名来由，对研究汉、魏、六朝的音乐\n相当有参考价值。\n",
        "唐代乐律学著作，对变声的强调和左旋、右旋两种旋宫之法的论述，颇有特点。\n",
        "敦煌石窟收藏的音乐文物抄录，记有二十五首曲谱。所用谱字称为「燕乐半字谱」，\n共计有二十多个，谱字旁有符号和文字表示音高和节奏。\n",
        "宋代诗歌谱集，歌词出自诗经，配以雅乐风格的曲调。\n",
});


void create()
{
	int num = random(4);

	set_name( names[num], ({ "music book", "book" }));
		set("long", longs[num]);
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
			"name":	"music",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 10, 	// jing cost every time study this
			"difficulty":	24,	// the base int to learn this skill
			"max_skill":	50,	// the maximum level you can learn
		]) );
	}
}
