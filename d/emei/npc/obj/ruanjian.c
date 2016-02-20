//Cracked by Roath
// longsword.c 长剑

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"软剑"NOR, ({ "ruanjian", "jian" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把普通的软剑，剑质轻柔，可围在腰间。\n");
		set("value", 250);
		set("material", "steel");
		set("rigidity", 300);
		set("wield_msg", "$N「唰」的一声展开一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n绕回腰间。\n");
	}
	init_sword(10);
	setup();
}
