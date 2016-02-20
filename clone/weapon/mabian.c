//Cracked by Roath

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("马鞭", ({ "ma bian", "bian" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄赶车骑马用的马鞭。\n");
		set("value", 100);
		set("material", "leather");
		set("rigidity", 100);
		set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(10);
	setup();
}
