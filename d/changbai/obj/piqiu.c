//Cracked by Roath
// piqiu.c


#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Æ¤ôÃ", ({ "pi qiu", "qiu", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}

