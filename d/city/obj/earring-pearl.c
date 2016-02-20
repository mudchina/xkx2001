//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIM "珍珠耳饰" NOR, ({ "pearl earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("value", 6000);
                set("long", "一对由美丽的小珍珠做成的耳饰，戴着它时可散发出迷人的光彩。\n");
                set("material", "pearl");
                set("armor_prop/armor", 5);
				set("female_only", 1);
        }
        setup();
}