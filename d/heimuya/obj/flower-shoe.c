//Cracked by Roath
// flower-shoe.c
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( "绣花鞋", ({ "flower shoes", "shoes"}) );
        set_color("$HIM$");
        set("long", "这是一双做工精细的红色绣花鞋。\n");
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "双");
                set("value", 1000);
                set("armor_prop/armor", 1 );
                set("female_only", 1);
        }
        setup();
}
