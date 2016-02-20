//Cracked by Roath
//xiapi.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( "霞披" , ({ "xia pi", "xiapi", "cape", "pi" }));
        set_color("$HIR$");
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件霞披，用上等的釉丝精工绣成。两个袖口分别绣着莲和藕的图样。
大红对襟上是一对龙凤呈祥。\n");
		set("material", "cloth");
		set("unit", "件");
		set("value", 12000);
		set("wear_msg", HIR "$N穿戴起霞披，轻轻地盖上大红盖头， 害羞地低下了头。\n" NOR);
		set("unequip_msg", HIM "$N慢慢地解下霞披，红霞飞上了双腮，弯下腰道个万福。\n" NOR);
		set("armor_prop/armor", 10);
		set("female_only", 1);

	}
	setup();
}
