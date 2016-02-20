//Cracked by Roath
// cloth: changpao.c


#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("圣火袍", ({ "shenhuo pao", "pao"}));
        set("long", "这是一件白色的长袍，袍的右下角上绣了一个红色的火焰。\n");
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 250);
                set("armor_prop/armor", 10);
        }
        setup();
}
