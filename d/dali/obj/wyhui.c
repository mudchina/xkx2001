//Cracked by Roath
// wyhui.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("乌夷大麾", ({ "da hui","hui" }) );
	set("long", "这是一黑色大麾，乌夷族男子都喜欢披此物。\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
