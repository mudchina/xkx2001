//Cracked by Roath
// weapon: tiegun.c
// Summer. 10/7/96
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("扁担", ({ "biandan", "bian" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根结实的扁担。\n");
                set("value", 40);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(7);
        setup();
}

