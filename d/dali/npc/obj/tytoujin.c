//Cracked by Roath
// tytoujin.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("台夷头巾", ({ "tou jin","toujin","jin" }) );
	set("long", "一条台夷男子扎的头巾，一般和身上穿的短裙同色。\n");
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
