//Cracked by Roath
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"过桥米线"NOR, ({"guoqiao mixian", "rice noodle", "mixian"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一碗热气腾腾的油浸的米粉，正是大理名菜过桥米线。\n");
		set("unit", "碗");
		set("value", 80);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}



