//Cracked by Roath

inherit F_LIQUID;
#include <weapon.h>
#include <ansi.h>

inherit HAMMER;
void create()
{
	set_name( BLU "颅钵" NOR, ({"lubo"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用颅骨制成的钵。\n");
		set("unit", "个");
		set("no_sell",1);
		set("value", 100);
		set("max_liquid", 10);
		set("regidity", 1000);
		set("wield_msg", "$N从腰间抽出一个$n，端在手里。\n");
                set("unequip_msg", "$N将$n收起来，挂回腰间。\n");
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 10,
		"drunk_supply": 10,
	]));
	init_hammer(30);
}
