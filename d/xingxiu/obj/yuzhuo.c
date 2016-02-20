//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name(HIG"翠玉手镯"NOR, ({ "jade bracelet", "bracelet", "zhuo" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个和阗翠玉造的手镯，色泽犹如翡翠。\n");
		set("unit", "个");
		set("value", 6000);
		set("material", "jade");
		set("armor_prop/armor", 2);
		set("female_only", 1);
	}
	setup();
}       
