//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("象牙戒指", ({ "ivory ring", "ring" }));
        set_color("$HIW$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个象牙材质的戒指，给人朴素无邪的感觉。\n");
                set("unit", "个");
                set("value", 4500);
                set("material", "ivory");
                set("armor_prop/armor", 3);
        }
        setup();
}       
