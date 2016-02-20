//Cracked by Roath
// Ryu

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("绸裙", ({ "skirt", "chouqun", "qun"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件色彩斑斓的绸裙\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 300);
        }
        setup();
}

