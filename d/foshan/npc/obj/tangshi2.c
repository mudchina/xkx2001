//Cracked by Roath

inherit ITEM;

int do_tear(string);
void init()
{
        add_action("do_tear", "tear");
}

void create()
{
	set_name("唐诗选辑", ({ "tangshi xuanji", "xuanji", "poem", "tangshi" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本线装书，里面有好多有名的唐诗。
第一页有一首蹩脚的诗：
	
	道义铁肩担，
	刀枪两袖藏。
	庙堂阔步进，
	天下胸中装。

一看便知是后人做的。

在书的边角处，由于被泪水打湿而显出几个字来：三  二  一  四

");
		set("value", 200);
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");

		set("material", "paper");
		set("skill", ([
			"name":	"tangshi-jian",	// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}

int do_tear(string arg)
{
	object me = this_player();
        if (!id(arg))
		return notify_fail("你要撕什么？\n");

        message_vision("$N把唐诗选辑撕得粉碎。\n", me);

        destruct(this_object());
        return 1;
}

