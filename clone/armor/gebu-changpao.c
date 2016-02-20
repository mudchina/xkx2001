//Cracked by Roath
// Jay 9/9/96 (Chairman Mao died twenty years ago.:(

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(GRN"葛布长袍"NOR, ({"changpao", "cloth","pao"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "这是粗葛布织的长袍，手摸上去很粗糙。\n");
        set("material", "cloth");
        set("armor_prop/armor", 15);
	set("value",500);
    }
    setup();
}
