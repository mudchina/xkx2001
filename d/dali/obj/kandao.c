//Cracked by Roath
// kandao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
#include "/clone/weapon/edge_weapon.h"

void create()
{
	set_name("砍刀", ({ "kan dao", "dao" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄小砍刀，刃身颇宽，没有护手，短小精悍。前端有一回钩，适合劈砍树木枝条。\n");
		set("value", 250);
		set("material", "steel");
		set("wield_msg", "$N拿出一柄$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
        }
	init_blade(10);
	setup();
}
