//Cracked by Roath
// 庄子
inherit ITEM;
inherit F_UNIQUE;

void init();

void create()
{
	set_name("《庄子》竹简", ({"zhujian", "bamboo" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
		else {
		set("value", 100);
		set("unit", "捆");
		set("huiwen",1);
		set("long", 
		"一捆竹简，简上涂了黑漆，简身仍属完整，简上用朱漆写着密密的汉字。\n"
		"头一句是“北冥有鱼，其名为鲲”，翻简看下去，见一篇篇都是《庄子》。\n"
		"只见中间有一片有些不同，每个字旁加了密密圈点，还写着几个古回文。\n");
		set("material", "bamboo");
	}
	setup();
	::create();
}

void init()
{
	add_action("do_lingwu", "lingwu");
}

int do_lingwu(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 
	int neili_lost;

	if (arg== "zhujian" || arg== "bamboo") {
		write("庄子教人达观顺天，跟武功全不相干。\n");
		return 1;
	}

	return 0;
}
