//Cracked by Roath
// gb_beef.c 牛肉条

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("牛肉条", ({"niurou tiao", "tiao", "beef"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗炙牛肉条，每条牛肉都是由四条小肉拼成，香气浓郁。\n");
		set("unit", "碗");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 20);
	}
}
