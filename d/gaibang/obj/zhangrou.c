//Cracked by Roath
// zhangrou.c â¯Èâ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("â¯Èâ", ({"zhang rou", "zhang"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éÏÊÑªÁÜÀìµÄâ¯Èâ¡£\n");
		set("unit", "¿é");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}
