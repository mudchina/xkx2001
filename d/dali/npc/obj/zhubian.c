//Cracked by Roath
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("竹匾", ({ "zhubian", "basket" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个作工精细的竹匾。\n");
                set("value", 200);
                set("material", "steel");
        }
        init_blade(8);
        setup();
}


