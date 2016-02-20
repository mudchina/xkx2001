//Cracked by Roath
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(MAG"百果油包"NOR, ({"baozi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("value", 70);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
