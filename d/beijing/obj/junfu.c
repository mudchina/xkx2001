//Cracked by Roath

// junfu.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("军服", ({ "junfu", "cloth" }));
        set_color("$HIW$");
        set("long", "这是一件有御林军侍卫统一的军服。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 0);
                set("armor_prop/armor", 15);
        }
        setup();
}
