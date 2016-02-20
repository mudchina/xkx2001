//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"蒙古战袍"NOR, ({"robe", "zhanpao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件蒙古武士所穿的战袍。\n");
        set("material", "cloth");
        set("armor_prop/armor", 20);
    }
    setup();
}
