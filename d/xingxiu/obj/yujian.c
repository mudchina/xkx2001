//Cracked by Roath
// jadesword.c 玉剑

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIW"玉剑"NOR, ({ "jade sword", "jian", "sword" }));
	set_weight(2500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄白色长剑，是白玉所造成，刃口磨得很是锋锐，和钢铁兵器不相上下。\n");
		set("value", 10000);
		set("material", "jade");
		set("rigidity", -10);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(25);
	setup();
}
