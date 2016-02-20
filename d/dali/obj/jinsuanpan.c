//Cracked by Roath
// weapon: /d/dali/npc/obj/jinsuanpan.c
// lyu

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("金算盘", ({ "jin suanpan", "suanpan" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把算帐用的算盘，却是纯金铸成的。\n");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N从背后取出一把$n，握在手中。\n");
                set("unwield_msg", "$N把手中的$n藏在背后。\n");
        }

        init_hammer(25);
        setup();
}

