//Cracked by Roath
// tongbo.c 铜钹

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("铜钹", ({ "tongbo", "bo" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "这是一对铜钹，钹边闪闪生光，锋利异常。\n");
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N取出一对$n，双手合处，当地一声，震耳欲聋。\n");
		set("unwield_msg", "$N将手中的$n收好。\n");
	}
	init_blade(30);
	setup();
}
