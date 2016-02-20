//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("瑶琴", ({ "yao qin", "qin" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这张琴颜色暗旧，是数百年乃至上千年的古物。\n");
                set("value", 300);
                set("material", "wood");
                set("wield_msg", "$N捧起一张$n在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
        }
        init_staff(25);
        setup();
}

