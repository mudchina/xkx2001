//Cracked by Roath
// maozhan.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("毛毡", ({ "mao zhan","zhan" }) );
	set("long", "这一张摆夷人男子经常穿戴的用动物皮毛编织成的毛毡。\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
