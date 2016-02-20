//Cracked by Roath
// Food: songguo.c 
// By Marz@XKX 11/12/96

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIG"野松果"NOR, ({"guo", "song guo"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗从林子里采来的野松果。\n");
		set("unit", "颗");
		set("value", 60);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}


