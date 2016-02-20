//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("白银项链", ({ "silver necklace", "necklace", "lace" }));
        set_color("$HIW$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一串白银制成的项链，民间相传，戴着它可以驱走一些妖魔。\n");
                set("unit", "串");
                set("value", 4000);
                set("material", "silver");
                set("armor_prop/armor", 2);
        }
        setup();
}       
