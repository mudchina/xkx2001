//Cracked by Roath
// byskirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("摆夷短裙", ({ "duan qun","qun","skirt" }) );
	set("long", "摆夷男女都喜穿这种长不过膝的白色丝织的短裙。\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
