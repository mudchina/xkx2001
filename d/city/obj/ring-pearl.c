//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("珍珠戒指", ({ "pearl ring", "ring" }));
        set_color("$HIM$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个珍珠做成的戒指，上面镶着一颗指头大小的明珠，发出柔和珠光。\n");
                set("unit", "个");
                set("value", 5500);
                set("material", "pearl");
                set("armor_prop/armor", 3);
        }
        setup();
}       
