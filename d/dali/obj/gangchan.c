//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("钢铲", ({ "gang chan", "chan" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄精钢打造的铲子，形式和佛门弟子用的方便铲差不多，唯独铲头较厚较钝且略有弯曲。\n");
		set("value", 350);
		set("material", "steel");
		set("wield_msg", "$N抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放了下来。\n");
	}
	init_staff(25);
	setup();
}

