// rose.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(HIR"红玫瑰"NOR, ({"rose", "mei gui"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long",
"一株盛开的红玫瑰，鲜艳欲滴。花束上一条小小的粉红绶带，上有细细一行小
字：欢迎回到你的家。\n");
                set("value", 0);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
        }
        setup();
}


