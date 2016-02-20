//Cracked by Roath
// pink_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("红绫袄", ({ "red cloth", "cloth" }) );
        set_color("$HIR$");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件红色的绫袄绣工精美，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 8);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

