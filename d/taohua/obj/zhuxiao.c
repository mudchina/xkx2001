//Cracked by Roath
// zhuxiao.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(GRN"竹箫"NOR,({ "zhu xiao", "xiao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 100);
		set("material", "bamboo");
                set("shape", "flute");
		set("long", "这是一柄三尺来长，精工制成的青竹箫。\n");
		set("wield_msg", "$N拿出一把$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_sword(7);
	setup();
}

#include "flute.h"
#include "music.h"
