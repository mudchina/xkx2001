//Cracked by Roath
// goldring.c 金戒指

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(HIY"金戒指"NOR, ({ "golden ring", "ring" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 1000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
