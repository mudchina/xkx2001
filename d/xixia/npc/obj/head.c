//Cracked by Roath
// 

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ÈËÍ·", ({"head", "rentou", "tou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¿Å");
		set("value", 0);
	}

	setup();
}

