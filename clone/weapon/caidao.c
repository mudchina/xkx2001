//Cracked by Roath
// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("菜刀", ({ "cai dao", "dao" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄精工打造的锋利菜刀。\n");
		set("value", 30);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n收起来。\n");
	}
	init_blade(3);
	setup();
}
