//Cracked by Roath
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("薄皮包子", ({"baozi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "薄皮包子皮薄似纸，色白油亮，内包羊肉馅，风味独到。\n");
		set("unit", "个");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}
