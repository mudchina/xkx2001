//Cracked by Roath

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIW"裘皮袄"NOR, ({ "qiu pi'ao", "ao" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件雪白的裘皮袄。\n");
                set("unit", "件");
                set("value", 1700);
                set("material", "fur");
                set("armor_prop/armor", 10);
        }
        setup();
}

