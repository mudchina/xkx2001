//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("珍珠项链", ({ "pearl necklace", "necklace", "lace" }));
        set_color("$HIM$");
        set("weight", 500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一串明珠做成的项链，浑圆无瑕，发出柔和的光芒。\n");
                set("unit", "串");
                set("value", 7000);
                set("material", "pearl");
                set("armor_prop/armor", 5);
        }
        setup();
}       
