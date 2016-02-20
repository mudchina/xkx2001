//Cracked by Roath
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
void create()
{
        set_name(HIM "琵琶" NOR, ({ "pi pa"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是把琴头雕有如意，用紫檀制成的四相十三品琵琶。\n");
                set("value", 0);
                set("material", "wood");
                set("wield_msg", "$N端起一把$n在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
                }
        init_hammer(45);
        setup();
}
