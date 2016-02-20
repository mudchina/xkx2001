//Cracked by Roath
// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "头盔" , ({ "tou kui", "kui" }) );
        set_color("$HIC$");
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
                set("long", "这是一顶金属头盔，用以保护头部。\n");
		set("value", 500);
		set("material", "iron");
		set("armor_prop/armor", 10);
		set("shaolin",1);
	}
	setup();
}
