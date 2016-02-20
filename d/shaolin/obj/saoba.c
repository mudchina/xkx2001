//Cracked by Roath
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("铁扫把", ({ "sao ba", "ba" }));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根黑黝黝的铁扫把，约百来斤，如手极为沉重。\n");
                set("material", "iron");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
	    set("shaolin",1);
        }
        init_staff(100);
        setup();
}

