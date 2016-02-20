//Cracked by Roath
// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("哈萨克长袍", ({ "hazakh robe", "robe"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件黑色的哈萨克长袍\n");
                set("material", "cloth");
                set("armor_prop/armor", 15);
                set("value", 100);
        }
        setup();
}

