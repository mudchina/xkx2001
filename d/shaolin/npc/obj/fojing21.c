//Cracked by Roath
// fojing21.c

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
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	40,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
		]) );
	}
}


/*void init()
{
	if( this_player() == environment() )
	{
		add_action("do_tear", "tear");
	}
}*/

int do_tear(string arg)
{
	object me, bible;
	object where;

	if ( !arg )
	{
		return notify_fail("什么？\n");
	}

	me = this_player();

	if ( arg == "jing" || arg == "shu" || arg == "book" )
	{
		bible = new(CLASS_D("shaolin")+"/obj/book-jiuyang");
		where = environment(me);
		message_vision("$N轻轻地把书撕掉……，突然从书缝中飘落出几页羊皮纸。\n",
			this_player());
		bible->move(file_name(where));
		destruct(this_object());
	}

	return 1;
}
