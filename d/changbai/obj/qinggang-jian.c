//Cracked by Roath
// gangjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("青刚剑", ({ "qinggang jian", "jian", "sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄青铁打成的长剑，剑刃上泛着青色的光茫。\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}

	init_sword(40);
	setup();
}
