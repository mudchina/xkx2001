//Cracked by Roath
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW"白袍"NOR, ({ "bai pao", "robe", "cloth" }));
        set("long", "这是一件白色的长袍。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 0);
                set("armor_prop/armor", 6);
        }
        setup();
}

