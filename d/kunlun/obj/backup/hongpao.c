//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"黄袍"NOR, ({ "robe", "pao"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件普通的黄色长袍，长袍边上绣着一个红色的火炎。\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 100);
        }
        setup();
}

