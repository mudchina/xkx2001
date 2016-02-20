//Cracked by Roath
// weapon: tiejiang.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("铁桨", ({ "tie jiang", "jiang" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根黑乎乎的铁桨，属于奇门兵器。\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N双手握起一根$n。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(30);
        setup();
}

