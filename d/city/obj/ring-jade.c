//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name("碧玉戒指", ({ "jade ring", "ring" }));
        set_color("$HIG$");
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个碧玉戒指，材质是在某些地方才有产的奇玉，异常贵重。\n");
                set("unit", "个");
                set("value", 6500);
                set("material", "jade");
                set("armor_prop/armor", 4);
        }
        setup();
}       
