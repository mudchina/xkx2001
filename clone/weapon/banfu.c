//Cracked by Roath
// weapon: banfu.c 板斧
// qfy August 19, 1996.

#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name(HIW"板斧"NOR, ({ "banfu", "fu", "axe" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把极具杀伤力的板斧，明晃晃的锋利之极。\n");
                set("value", 300);
                set("material", "steel");
                set("wield_msg", "$N双手提起$n。\n");
                set("unwield_msg", "$N放下$n。\n");
        }
        init_axe(30);
        setup();
}

