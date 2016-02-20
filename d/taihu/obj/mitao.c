//Cracked by Roath
// mitao.c 水蜜桃
// By Marz

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("水蜜桃", ({"tao", "mi tao"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟水灵新鲜的水蜜桃，跟小翠的脸蛋儿一样红艳可人。\n");
		set("unit", "碟");
		set("value", 60);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
