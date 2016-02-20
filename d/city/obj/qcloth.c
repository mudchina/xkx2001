//Cracked by Roath
#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(CYN"Çà²¼ÒÂ"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

