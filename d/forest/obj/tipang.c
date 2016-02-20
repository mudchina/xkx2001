//Cracked by Roath

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Â±ÖíÌã°ò", ({"tipang", "ti"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅÌÂ±ÖíÌã°ò\n");
		set("unit", "ÅÌ");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
