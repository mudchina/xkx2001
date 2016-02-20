//Cracked by Roath
// fake-gold.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"黄金"NOR, ({"gold", "ingot", "gold_money"}));
	set_weight(150000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "黄澄澄的金子，人见人爱的金子，不过 ...颜色有点不对。\n");
		set("unit", "块");
		set("material", "lead");
	}
	setup();
}

