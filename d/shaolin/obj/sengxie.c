//Cracked by Roath

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIC "ɮЬ" NOR, ({ "seng xie", "xie" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫�಼ɮЬ��\n");
		set("value", 250);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("shaolin",1);
	}
	setup();
}
