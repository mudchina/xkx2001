//Cracked by Roath
// xiupao.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( RED"大红箭袖袍"NOR, ({ "xiu pao", "pao"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件做工精细的大红箭袖袍。\n");
                set("unit", "件");
                set("value", 300);
                set("material", "cloth");
                set("armor_prop/armor", 6);
        }
        setup();
}

