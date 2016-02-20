//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(YEL "琥珀耳饰" NOR, ({ "amber earring", "earring" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("value", 3000);
                set("long", "一对琥珀做坠的耳饰，散发着琉璃的光彩。\n");
                set("material", "amber");
                set("armor_prop/armor", 2);
				set("female_only", 1);
        }
        setup();
}