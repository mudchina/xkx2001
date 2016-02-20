//Cracked by Roath
#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
	set_name(GRN"鳄尾鞭"NOR, ({ "ewei bian", "bian" }));
//	set_color("$GRN$");
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄由鳄鱼的尾巴做成的鞭子，鞭子上倒插着一根根钢针。\n");
		set("value", 7000000);
		set("rigidity", 100000);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(170);
	setup();
}
