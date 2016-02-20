//Cracked by Roath
// weapon: /d/xingxiu/npc/obj/yaochu.c
// Jay 3/18/96

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("铁算盘", ({ "tie suanpan", "suanpan" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把算帐用的算盘，却是精铁所制。\n");
                set("value", 1000);
                set("material", "iron");
                set("wield_msg", "$N从背后取出一把$n，握在手中。\n");
                set("unwield_msg", "$N把手中的$n藏在背后。\n");
        }

        init_hammer(15);
        setup();
}

