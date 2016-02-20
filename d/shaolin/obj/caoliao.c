//Cracked by Roath
// caoliao.c 草料

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("草料", ({"cao", "cao liao"}));
	set_weight(200+random(200));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一捆喂养家畜用的草料。\n");
		set("unit", "捆");
		set("value", 20+random(50));
		set("food_remaining", 1);
		set("food_race","家畜");
		set("food_supply", random(100));
	}
}
