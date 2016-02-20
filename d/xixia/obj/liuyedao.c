//Cracked by Roath
// jiedao.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(GRN"柳叶刀"NOR, ({ "liuyedao", "dao", "blade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 250);
		set("material", "iron");
		set("long", "这是一把尺半长的钢刀，形似柳叶，入手轻飘，乃是女子常用兵器。\n");
		set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n卷入腰间。\n");
	}
	init_blade(30);
	setup();
}
