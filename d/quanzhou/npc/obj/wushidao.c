//Cracked by Roath
// wushidao.c 武士刀

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("武士刀", ({ "wushi dao", "dao", "blade" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 300);
		set("material", "steel");
		set("long", "这是一把日本浪人常用的武士刀，刀身修长，略作弧形，刃口极为锋利。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(30);
	setup();
}
