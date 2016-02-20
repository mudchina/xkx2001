//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("蒸豆腐", ({"zheng doufu", "steamed tofu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟蒸豆腐，有点象黄蓉烧过的「二十四桥明月夜」。\n");
		set("unit", "碟");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 15);
	}
}
