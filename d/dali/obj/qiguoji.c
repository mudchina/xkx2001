//Cracked by Roath
// qiguoji.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(MAG"汽锅鸡"NOR, ({"qiguo ji", "soup", "ji" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "云南的名菜汽锅鸡，是用汽锅炖得烂烂的鸡汤。\n");
		set("unit", "盆");
		set("value", 120);
		set("remaining", 3);
		set("drink_supply", 60);
		set("food_supply", 50);
	}
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	if (arg!="qiguo ji" && arg!="soup" && arg!="ji") return 0;
	if (this_player()->is_busy())
		return notify_fail("你上一个动作还没有完成。\n");

	if ((int)this_player()->query("water")
		>= (int)this_player()->max_water_capacity() )
		return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");
	if ((int)this_player()->query("food")
		>= (int)this_player()->max_food_capacity() )
		return notify_fail("你已经吃得太多了，再也撑不下任何东西了。\n");

	set("value", 0);
	this_player()->add("water", (int)query("drink_supply"));
	this_player()->add("food", (int)query("food_supply"));

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	add("remaining", -1);
	if (query("remaining")) {
		message_vision("$N在盅里舀起一大勺鸡肉带着鸡汤，大口吃了起来。\n",this_player());
	}
	else {
		message_vision("$N端起汽锅，把剩下的连鸡带汤一扫而尽。\n",this_player());
		destruct(this_object());
	}
	return 1;
}
