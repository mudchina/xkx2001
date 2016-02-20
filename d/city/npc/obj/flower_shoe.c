//Cracked by Roath
// shoe.c
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( MAG"绣花小鞋"NOR, ({ "flower shoes", "shoes"}) );
        set("long", "这是一双做工精细的绣花小鞋。\n");
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "双");
		set("value", 100);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}
