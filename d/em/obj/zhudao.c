//Cracked by Roath
// zhudao.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(GRN"竹刀"NOR,({ "zhu dao", "dao", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 75);
		set("material", "bamboo");
		set("long", "这是一柄精工制成的青竹短刀，峨嵋弟子习武均用此刀，以免伤人。\n");
		set("wield_msg", "$N抽出一把$n，握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(10);
	setup();
}
