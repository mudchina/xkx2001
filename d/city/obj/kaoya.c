//Cracked by Roath
// kaoya.c 烤鸭

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void init();
int do_cut(string);

void create()
{
	set_name(MAG"烤鸭"NOR, ({"kaoya", "ya"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只肥得流油的北京烤鸭。\n");
		set("unit", "只");
		set("value", 120);
		set("food_remaining", 3);
		set("food_supply", 80);
	}

	setup();
}

void init()
{
        add_action("do_cut", "cut");
}

int do_cut(string arg)
{
        object ob1 = this_object(), me = this_player();

	if ( !arg || arg == "") return 0;

	if ( arg == "烤鸭" || arg == "kaoya" ) {
        	object ob2 = new("/clone/food/yazhang");
		message_vision("$N把烤鸭的鸭掌切了下来。\n", me);
		ob2->move(me);
		destruct(ob1);
		return 1;
	}
	return 0;
}

