//Cracked by Roath
// weapon: qiang.c
// qfy August 23, 96

#include <weapon.h>

inherit PIKE; 

void create()
{
        set_name("长枪", ({ "chang qiang", "qiang" }) );
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄长枪，枪头上有一束红缨。\n");
                set("value", 200);
                set("material", "iron");
                set("wield_msg", "$N拿出一柄$n，抖了个枪花，红缨闪动。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_pike(20);
        setup();
}

