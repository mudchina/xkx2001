//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY"±¥ø«œÓ¡¥"NOR, ({ "shell lace", "lace" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¥Æ");
                set("value", 1000);
                set("material", "gold");
                set("armor_prop/armor", 1);
        }
        setup();
}       













