//Cracked by Roath
// acep , mantian , mantian

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name( CYN "花锄" NOR , ({ "huachu", "chu" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄小锄头，木把，铁头，是花匠种花除草的好工具。\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N抄起一柄$n，握在手中当武器。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_hammer(10);
	setup();
}
