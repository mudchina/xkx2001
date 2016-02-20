//Cracked by Roath
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("熟铜棍", ({ "tong gun", "gun" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", 
"这是一根黄澄澄的熟铜棍，看来没有几百斤臂力是难以使动的。\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_club(10);
        setup();
}

