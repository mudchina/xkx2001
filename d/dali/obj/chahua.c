//Cracked by Roath
// chahua.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"山茶花"NOR, ({"cha hua", "cha"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一株盛开的茶花，几朵不同色的大花开放在一枝，看来定然十分名贵不是凡品。\n");
		set("unit", "株");
        set("material", "wood");
	}
}
