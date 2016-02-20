//Cracked by Roath
// axe.c 斧头

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("斧头", ({ "axe","fu" }));
	set_weight(9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把斧头，可以用来砍树。\n");
		set("value", 1000);
		set("material", "steel");
		set("no_drop",1);
	}
	init_axe(10);
	setup();
}

