//Cracked by Roath
// green_beixin.c 青缎掐牙背心

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "青缎掐牙背心", ({ "qing beixin", "beixin" }) );
	set_color(GRN);
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 300);
                set("material", "cloth");
                set("armor_prop/armor", 6);
        }
        setup();
}

