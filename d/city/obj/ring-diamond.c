//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(HIW"钻石戒指"NOR, ({ "diamond ring", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一枚白银为环，钻石为体，由顶级工匠切磨成八边层阶形的华丽钻石戒指。\n");
                set("unit", "个");
                set("value", 18000);
                set("material", "diamond");
                set("armor_prop/armor", 5);
        }
        setup();
}       
