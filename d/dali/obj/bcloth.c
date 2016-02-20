//Cracked by Roath
// bcloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name("บฺาย", ({ "cloth" }) );
        set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ผþ");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}

