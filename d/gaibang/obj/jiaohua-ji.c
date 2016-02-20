//Cracked by Roath
// jiaohuaji.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("叫化鸡", ({"jiaohua-ji", "ji"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只被烤得流油，香味扑鼻的叫化鸡。\n");
		set("unit", "只");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 30);
	}
}
