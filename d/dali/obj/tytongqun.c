//Cracked by Roath
// tytongqun.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("筒裙", ({ "tong qun","qun","skirt" }) );
	set("long", "一条台夷女子爱穿的五色筒裙，长及脚踝。\n");
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
