//Cracked by Roath
// rose.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIW "白玫瑰" NOR, ({"bai meigui", "bai"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵含苞欲放的白色玫瑰，象征着美，爱，恋。\n");
		set("unit", "朵");
		set("value", 45);
		set("base_unit", "朵");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}
#include "flower.h"