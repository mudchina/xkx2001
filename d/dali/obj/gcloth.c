//Cracked by Roath
// gcloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( GRN "µ­ÂÌ³íÉÀ" NOR , ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

