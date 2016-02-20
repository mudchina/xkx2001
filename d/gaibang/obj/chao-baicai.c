//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("³´°×²Ë", ({"chao baicai", "baicai"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÍëÅçÏãµÄ³´°×²Ë¡£\n");
		set("unit", "Íë");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 15);
	}
}
