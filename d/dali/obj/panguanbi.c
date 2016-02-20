//Cracked by Roath
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("判官笔", ({ "panguan bi", "bi" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long", 
"这是一对三尺六寸长的判官笔，透体通黑。\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N拿出一对$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_sword(20);
        setup();
}

