//Cracked by Roath
// tofu.c 豆腐

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("翡翠豆腐", ({"doufu", "tofu"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块水灵灵的大豆腐，嫩得令人不禁想到大姑娘的脸蛋儿。\n");
		set("unit", "块");
		set("value", 25);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}
