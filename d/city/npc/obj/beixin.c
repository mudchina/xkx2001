//Cracked by Roath

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( YEL"皮背心"NOR, ({ "pi beixin", "beixin" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件皮背心。\n");
                set("unit", "件");
                set("value", 300);
                set("material", "leather");
                set("armor_prop/armor", 6);
        }
        setup();
}

