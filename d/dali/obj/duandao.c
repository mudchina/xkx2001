//Cracked by Roath
// duandao.c
// acep , mantian , mantian

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("短刀", ({ "blade" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄刃身极阔的短刀，是神农帮帮众的标准武器。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声拔出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(20);
	setup();
}
