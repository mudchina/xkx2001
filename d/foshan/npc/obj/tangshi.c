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
		set("long", "这是一本线装书，里面有好多有名的唐诗。\n");
		set("value", 200);
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

