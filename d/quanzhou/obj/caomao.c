//Cracked by Roath
// caomao.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "草帽" , ({ "cao mao", "mao" }) );
        set_color("$HIG$");
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
                set("long", "这是一顶新编的草帽。\n");
		set("value", 150);
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	setup();
}
