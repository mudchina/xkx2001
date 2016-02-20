//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("琥珀项链", ({ "amber necklace", "necklace", "lace" }));
        set_color("$YEL$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一串以琥珀做成的项链，琥珀是树汁的结晶，让人感觉它蕴藏着神秘的力量。\n");
                set("unit", "串");
                set("value", 5000);
                set("material", "amber");
                set("armor_prop/armor", 3);
        }
        setup();
}       
