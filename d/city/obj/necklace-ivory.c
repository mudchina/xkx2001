//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("象牙项链", ({ "ivory necklace", "necklace", "lace" }));
        set_color("$HIW$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一串象牙项链，全部材质皆为象牙，非常珍贵。\n");
                set("unit", "串");
                set("value", 6000);
                set("material", "ivory");
                set("armor_prop/armor", 4);
        }
        setup();
}       
