//Cracked by Roath
// 

#include <weapon.h>

inherit PIKE;

void create()
{
        set_name("火叉", ({ "huo cha", "cha" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄火叉，看上去钝钝的。\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N拿出一柄$n，抖了一抖，傻笑了几声。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_pike(50);
        setup();
}

