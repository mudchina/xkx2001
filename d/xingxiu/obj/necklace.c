//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(HIW"脂玉项链"NOR, ({ "jade necklace", "necklace", "lace" }));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一串由和阗脂玉串成的项链，玉色温润如羊脂，洁白无瑕。\n");
		set("unit", "串");
		set("value", 6000);
		set("material", "jade");
		set("armor_prop/armor", 2);
		set("female_only", 1);

	}
	setup();
}       
