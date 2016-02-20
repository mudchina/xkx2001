//Cracked by Roath
// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "œ‚±ﬂ∫…“∂Û“" , ({ "heye li", "li" }) );
        set_color("$HIG$");
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "∂•");
                set("long", "’‚ «“ª∂•œ‚±ﬂ∫…“∂Û“°£\n");
		set("value", 150);
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("female_only",1);
	}
	setup();
}
