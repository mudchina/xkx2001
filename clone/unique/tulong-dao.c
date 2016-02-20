//Cracked by Roath
//tulong-dao 屠龙刀

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name("屠龙刀", ({ "tulong dao", "dao", "blade" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","这是一柄四尺来长、乌沉沉的单刀，看上去黑黝黝的毫不起眼。\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 3000);
		set("wield_msg", HIY "只见黑光一闪，$N手中已多了一柄黑沉沉的大刀：
武林至尊，宝刀屠龙，号令天下，莫敢不从！\n" NOR);
		set("unwield_msg",HIY"$N仰天一声清啸，伸手在屠龙刀上一弹，放入长袍之内。\n" NOR);
	}
	init_blade(180);
	setup();
	::create();
}


