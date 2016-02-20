//Cracked by Roath
// rose.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIW "牡丹" NOR, ({"mu dan", "mu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵雍容华贵的牡丹花，花朵婀娜多姿，委实令人心醉神迷。\n");
		set("unit", "朵");
		set("value", 100);
		set("base_unit", "朵");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}
#include "flower.h"