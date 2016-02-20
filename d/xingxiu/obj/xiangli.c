//Cracked by Roath
// maco

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("香梨", ({"xiang li", "li"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "库尔勒出产的香梨，以质地酥脆、汁多果香、肉细味甜而闻名。\n");
		set("unit", "个");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 15);
	}
}
