//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW "象牙耳饰" NOR, ({ "ivory earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("value", 5000);
                set("long", "一对以象牙做成的耳饰，形状非常巨大。\n");
                set("material", "ivory");
                set("armor_prop/armor", 4);
				set("female_only", 1);
        }
        setup();
}