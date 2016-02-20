//Cracked by Roath
// jiaohuaji.c 好逑汤

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("好逑汤", ({"haoqiu tang", "soup"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗碧绿的清汤。\n");
		set("unit", "碗");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 15);
	}
}
