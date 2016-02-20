//Cracked by Roath
// moon_dress.c 琼花皎月裳
// xQin 8/00 

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( HIW "琼花皎月裳" NOR, ({ "dress" }) );
        set("long",
        "这是一件用上好布料巧制而成的琼花皎月裳。\n");
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 2000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/personality", 2);
                set("armor_prop/armor", 3);
                set("female_only", 1);
                set("wear_msg","$N穿上一件$n，只见$N微微一笑，娇丽如花。\n");
                set("remove_msg","$将$n脱了下来。\n");
        }
}

