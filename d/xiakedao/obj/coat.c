//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("油布雨衣", ({ "rain coat", "coat"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件油布雨衣。\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 0);
        }
        setup();
}

