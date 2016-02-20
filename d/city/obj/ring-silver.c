//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("银戒指", ({ "silver ring", "ring" }));
        set_color("$HIW$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个银制的戒指，一般戴做装饰。\n");
                set("unit", "个");
                set("value", 3500);
                set("material", "silver");
                set("armor_prop/armor", 2);
        }
        setup();
}       
