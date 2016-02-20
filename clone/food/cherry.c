//Cracked by Roath
// cherry.c 樱桃

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"樱桃"NOR, ({"ying tao", "cherry"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟水灵新鲜，红艳可人的樱桃。\n");
		set("unit", "碟");
		set("value", 60);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
