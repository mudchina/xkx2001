//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("铁戒指", ({ "iron ring", "ring" }));
        set_color("$HIC$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个寻常的戒指，作为一般民间的装饰品，材质为铁。\n");
                set("unit", "个");
                set("value", 2500);
                set("material", "iron");
                set("armor_prop/armor", 1);
        }
        setup();
}       
