//Cracked by Roath
// emei_shoes.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("青布女履", ({ "shoes"}) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", 
"这是一双青布女履。\n");
		set("material", "cloth");
                set("armor_type", "boots");
                set("armor_prop/armor", 1);
                set("female_only", 1);
	}

}
