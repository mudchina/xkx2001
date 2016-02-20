//Cracked by Roath
// gangdao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIW"缅刀"NOR, ({ "mian dao", "blade", "dao" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄又长又薄，弯弯的缅刀。\n");
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(25);
	setup();
}
