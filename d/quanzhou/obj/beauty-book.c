//Cracked by Roath

inherit ITEM;
void create()
{
	set_name("陈圆圆手帕", ({ "shoupa" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "方");
		set("long", "这是一方陈圆圆用过的手帕，上面有淡淡的香气，可以用来擦(ca)汗，上面绣着“珂儿珍重”四字。\n");
		set("value", 10000);
		set("material", "paper");
		set("skill", ([
			"name":	"beauty",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	15,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	150	// the maximum level you can learn
		]) );
	}
}

void init()
{
        add_action("do_ca","ca");
}

int do_ca(string arg)
{
	object who;
	object me = this_player();

	if (!arg) {
		message_vision("$N用" + query("name")+"给自己擦擦汗。\n", me);
		return 1;
	}
	if (!(who = present(arg, environment(me))) ||
		! who->is_character()) {
		write("这里没有这个人。\n");
		return 1;
	}

	if (who == me) {
                message_vision("$N用" + query("name")+"给自己擦擦汗。\n", me);
                return 1;
        }
	message_vision("$N用" + query("name")+"给$n擦擦汗。\n", me,who);
	tell_object(who,"你闻到一股淡淡的香气，莫非有毒！？\n");
	return 1;
}
