//Cracked by Roath
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("铁笛", ({ "tie di", "di" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", 
"这是一只生铁所铸的笛子，看起来沉掂掂的。\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N拿出一铁笛$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_sword(20);
        setup();
}

