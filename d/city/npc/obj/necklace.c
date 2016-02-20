//Cracked by Roath
// necklace.c 金项链
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name("金项链", ({ "golden necklace", "necklace", "lace" }));
        set_color("$HIY$");
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("value", 1500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
