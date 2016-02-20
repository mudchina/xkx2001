//Cracked by Roath
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIC"白衣"NOR, ({ "bai yi", "cloth" }));
        set("long", "这是一件白色的摆夷民服。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 500);
		                set("female_only", 1);

                set("armor_prop/armor", 6);
        }
        setup();
}

