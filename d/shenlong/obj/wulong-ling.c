//Cracked by Roath
// lingpai.c
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(RED"令牌"NOR, ({ "lingpai", "pai" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("value", 50);
		set("material", "wood");
		set("long", "这是一支木令牌，上面用朱漆写着一个「神龙」两字。\n");
//		set("wield_msg", "$N抽出一支$n握在手中。\n");
//		set("unwield_msg", "$N将手中的$n插回怀里。\n");
	}
//	init_blade(4);
	setup();
}
