//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("黑钢杖", ({ "heigang zhang", "zhang", "staff" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根黑钢杖，是件威力巨大的重兵器。\n");
                set("value", 350);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
        }
        init_staff(55);
        setup();
}

