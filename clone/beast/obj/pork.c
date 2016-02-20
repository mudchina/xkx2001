//Cracked by Roath
// pork.c ÖíÈâ
// xbc 06/21/97

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Ğ¡Öí¶ú¶ä", ({"zhu erduo", "zhu rou", "pork"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿éĞ¡Öí¶ú¶äÈâ¡£\n");
		set("unit", "¿é");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 20);
	}
}
