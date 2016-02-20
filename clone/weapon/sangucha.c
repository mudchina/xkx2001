//Cracked by Roath
// sangucha 三股叉

#include <weapon.h>

inherit PIKE;

void create()
{
        set_name("三股叉", ({ "san gu cha", "cha" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄三股叉，三根尖锐的叉子令人心寒。\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N拿出一柄$n，抖了一抖，发出一阵乱鸣。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_pike(30);
        setup();
}

