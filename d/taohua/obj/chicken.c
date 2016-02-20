//Cracked by Roath
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"°×ÇÐ¼¦"NOR, ({"chicken"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ö»");
		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 80);
	}
}
