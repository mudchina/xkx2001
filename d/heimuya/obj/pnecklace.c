//Cracked by Roath
// pnecklace.c 白金项链
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("白金项链", ({ "platinium necklace", "necklace", "lace" }));
        set_color("$HIW$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("value", 18500);
                set("material", "platinium");
                set("armor_prop/armor", 1);
        }
        setup();
}       
