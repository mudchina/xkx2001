//Cracked by Roath

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ª¨Ï÷¿Ôºπ", ({"liji", "li"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "“ª≈Ãª¨Ï÷¿Ôºπ\n");
		set("unit", "≈Ã");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
