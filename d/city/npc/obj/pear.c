//Cracked by Roath
// pear 锡山鸭梨
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鸭梨", ({"ya li", "li", "pear"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个新鲜香甜的鸭梨。\n");
		set("unit", "个");
		set("value", 20);
		set("food_remaining", 2);
		set("food_supply", 15);
	}
}
