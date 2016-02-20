//Cracked by Roath
// weapon: /d/xingxiu/npc/obj/yaochu.c
// Jay 3/18/96

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("铁锅", ({ "tie guo", "guo" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "这是一口烧饭用的大铁锅，已经有些生锈了。\n");
                set("value", 30);
                set("material", "iron");
                set("wield_msg", "$N从背后取出一口$n，握在手中。\n");
                set("unwield_msg", "$N把手中的$n背在背后。\n");
        }

        init_hammer(7);
        setup();
}

