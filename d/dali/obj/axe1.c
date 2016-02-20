//Cracked by Roath
#include <weapon.h>
inherit AXE;

void create()
{
        set_name("锈铁斧", ({ "xiu tiefu", "axe" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄精钢打造的斧头。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", 
"$N「唰」的一声拔出一柄精光闪闪的斧头握在手里。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_axe(20);
        setup();
}

