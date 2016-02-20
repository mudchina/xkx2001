//Cracked by Roath

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"青色长袍"NOR, ({"pao", "cloth", "chang pao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件普普通通的青色长袍。\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
