//Cracked by Roath
// yangrou.c ÑòÈâ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÑòÈâ", ({"yang rou", "lamb"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿é¸áÑò×øÍÎ¡£\n");
		set("unit", "¿é");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
