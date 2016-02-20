//Cracked by Roath

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("飘缈魔君", ({ "rover" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一件有魔力的衣服，闻起来还有一股淡香，穿上去感觉很飘缈。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
        }
        setup();
}

