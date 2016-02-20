//Cracked by Roath

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name( MAG "貂裘" NOR, ({ "diao qiu", "qiu" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
                set("long", "这是一条锦毛貂皮围脖。\n");
		set("value", 500);
		set("material", "leather");
		set("armor_prop/armor", 5);
		set("shaolin",1);
	}
	setup();
}
