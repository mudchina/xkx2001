//Cracked by Roath
// douli.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "¥Û∫Ï–…’±∂∑Û“" , ({ "dou li", "li" }) );
        set_color("$HIG$");
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "∂•");
                set("long", "’‚ «“ª∂•¥Û∫Ï–…’±∂∑Û“°£\n");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 4);
	}
	setup();
}
