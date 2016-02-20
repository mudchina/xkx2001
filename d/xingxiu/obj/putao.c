//Cracked by Roath
// maco

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ÆÏÌÑ", ({"grape", "putao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»´®ÍÂÂ³·¬³ö²úµÄÆÏÌÑ£¬¿Å¿ÅÏÊÂÌ¾§ÁÁ£¬¸ÊÌğ·¼Ïã¡£\n");
		set("unit", "´®");
		set("value", 20);
		set("food_remaining", 6);
		set("food_supply", 10);
		set("eat_msg","$N³ÔÏÂÁË¼¸¿ÅÆÏÌÑ¡£");
	}
}
