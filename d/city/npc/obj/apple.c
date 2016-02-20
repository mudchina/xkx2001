//Cracked by Roath
// apple 国光苹果
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("苹果", ({"ping guo", "guo"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个新鲜香甜的大红苹果。\n");
		set("unit", "个");
		set("value", 20);
		set("food_remaining", 3);
		set("food_supply", 10);
	}
}
