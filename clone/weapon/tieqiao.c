//Cracked by Roath
// weapon: /d/xingxiu/npc/obj/yaochu.c
// Jay 3/18/96

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("铁锹", ({ "tie qiao", "qiao" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把开山挖石用的铁锹，已经有些生锈了。\n");
                set("value", 150);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(10);
        setup();
}

