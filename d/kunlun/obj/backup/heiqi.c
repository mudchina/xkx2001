//Cracked by Roath
// weapon: heiqi.c
// long Apirl 13, 97

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("小黑旗", ({ "hong qi", "qi" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long", "这是一面连杆不到二尺的黑色小旗，旗上绣着个明教的火炎记号\n");
                set("value", 0);
                set("material", "");
                set("wield_msg", "$N拿出一柄$n。\n");
                set("unwield_msg", "$N把$n插回背後。\n");
        }
        init_halberd(20);
        setup();
}
