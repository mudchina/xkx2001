//Cracked by Roath
// stick.c

#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
	set_name("木棒", ({ "mu bang", "bang", "walking stick", "stick" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根木棒，可以当做爬山用的手杖。\n");
		set("value", 50);
		set("material", "wood");
		set("wield_msg", "$N拿出一根$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_stick(5);
	setup();
}
