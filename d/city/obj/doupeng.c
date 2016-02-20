//Cracked by Roath
// doupeng.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "∂∑≈Ò" , ({ "dou peng", "peng" }) );
        set_color("$HIG$");
	set_weight(550);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "∂•");
                set("long", "’‚ «“ª∂•∂∑≈Ò°£\n");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 4);
	}
	setup();
}
