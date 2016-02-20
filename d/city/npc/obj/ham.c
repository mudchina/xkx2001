//Cracked by Roath
// ham.c 火腿

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("火腿", ({"huo tui", "ham"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只又香又肥的火腿。\n");
		set("unit", "只");
		set("value", 120);
		set("food_remaining", 4);
		set("food_supply", 60);
	}
}
