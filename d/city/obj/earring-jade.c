//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIG "碧玉耳饰" NOR, ({ "jade earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("value", 7000);
                set("long", "一对以碧玉做成的耳饰，凝视着它，有让人心广神怡的感觉。\n");
                set("material", "jade");
                set("armor_prop/armor", 6);
				set("female_only", 1);
        }
        setup();
}