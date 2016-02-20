//Cracked by Roath
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("指环", ({ "zhi huan", "huan", "ring" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一枚金指环，上面有一些细细的花纹。\n");
		set("unit", "枚");
		set("value", 500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
