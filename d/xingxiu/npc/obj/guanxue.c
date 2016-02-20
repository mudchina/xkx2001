//Cracked by Roath
// AceP
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( CYN "官靴" NOR , ({ "guan xue", "xue" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "一双大理官员的标准官靴，鞋底很厚，走远路时，可以很好地保护双脚。");
		set("value", 300);
		set("material", "boots");
		set("armor_prop/armor", 6);
	}
	setup();
}
