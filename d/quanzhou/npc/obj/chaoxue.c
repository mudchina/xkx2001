//Cracked by Roath
// chaoxue.c
// xbc: 11/18/96

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(BLU"小朝靴"NOR, ({ "chao xue", "boots", "shoes"}) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long",  "这是一双青缎粉底小朝靴。\n");
                set("value", 100);
		set("material", "cloth");
                set("armor_type", "boots");
                set("armor_prop/armor", 2);
	}

}
