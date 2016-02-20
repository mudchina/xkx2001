//Cracked by Roath
// 御前侍卫服

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("御前侍卫服", ({ "shiwei cloth", "cloth" }));
        set_color("$BLU$");
        set("long", "这是一件御前侍卫统一穿着的军服。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 0);
                set("armor_prop/armor", 20);
        }
        setup();
}
