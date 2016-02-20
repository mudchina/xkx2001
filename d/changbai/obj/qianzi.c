//Cracked by Roath
// qianzi


#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("鹿骨钎子", ({ "lugu qianzi", "qianzi" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把鹿骨制成的钎子，用它可以把参从土中起(wa)出。\n");
                set("value", 100);
                set("material", "steel");
        }
        init_sword(5);
        setup();
}

