//Cracked by Roath
// wyskirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("乌夷长裙", ({ "chang qun","qun","skirt" }) );
	set("long", "这是一件乌夷妇女常穿的丝织黑色长裙，其长曳地。\n");
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
