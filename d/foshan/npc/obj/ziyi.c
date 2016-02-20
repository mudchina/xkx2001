//Cracked by Roath
// pink_cloth.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(MAG"紫绸衫"NOR, ({ "zi yi", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件紫色的绸衫，闻起来有一股淡香。\n");
		set("unit", "件");
		set("value", 300);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

