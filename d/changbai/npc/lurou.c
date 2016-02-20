//Cracked by Roath

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Â¹Èâ", ({"lu rou", "rou"}));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÏÊÑªÁÜÀì·ÊµÄÂ¹Èâ¡£\n");
		set("unit", "¿é");
		set("value", 50);
		set("food_remaining", 8);
		set("food_supply", 50);
//		set("food_race","Ò°ÊŞ");
	}
}
