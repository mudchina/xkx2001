//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"白色对襟衣"NOR, ({ "bai guazi", "guazi", "cloth"}) );
        set_weight(850);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件做工精细的白色对襟衣。\n");
                set("unit", "件");
                set("value", 350);
                set("material", "cloth");
                set("armor_prop/armor", 4);
                set("armor_prop/personality", 3);
        }
        setup();
}











