//Cracked by Roath
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(BLU"叶儿粑"NOR, ({"ye er ba", "cake"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一块飘着清香的叶ㄦ粑。\n");
		set("unit", "块");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 50);
	}
}






