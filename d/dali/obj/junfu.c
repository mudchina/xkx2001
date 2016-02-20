//Cracked by Roath
// junfu.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name( CYN "军服" NOR , ({ "junfu", "cloth" }));
	set("long", "这是一件大理官兵的标准军服。\n");
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 500);
		set("armor_prop/armor", 35);
	}
	setup();
}
