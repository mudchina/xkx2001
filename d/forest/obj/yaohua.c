//Cracked by Roath

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("±¬³´Ñü»¨", ({"yaohua", "yao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÅÌ±¬³´Ñü»¨\n");
		set("unit", "ÅÌ");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
