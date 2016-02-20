//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"黄色喇嘛袈裟"NOR, ({"lama jiasha", "cloth", "jiasha"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件西藏喇嘛日常穿的黄色袈裟。\n");
        set("material", "cloth");
        set("armor_prop/armor", 20);
    }
    setup();
}
