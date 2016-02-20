//Cracked by Roath
// weapon: fachu.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("法杵", ({ "fa chu", "fa","chu" }) );
        set_weight(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根做法事的法杵，也是僧家的防身武器。\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(20);
        setup();
}

