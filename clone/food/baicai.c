//Cracked by Roath
// baicai °×²Ë

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("°×²Ë", ({"baicai", "vegetable"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿ÅÐÂÏÊµÄ´ó°×²ËÐÄ¡£\n");
		set("unit", "¿Å");
		set("value", 20);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
