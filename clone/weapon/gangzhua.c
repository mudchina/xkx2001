//Cracked by Roath

#include <weapon.h>
#include <ansi.h>
inherit PIKE;
void create()
{
        set_name("钢爪", ({ "gang zhua", "zhua" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把奇形兵刃，柄长三尺，尖端是一支五指钢爪。\n");
                set("value", 200);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_pike(50);
        setup();
}

