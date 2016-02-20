//Cracked by Roath
// lingpai.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(RED"令牌"NOR, ({ "lingpai", "dao", "blade" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("value", 40);
		set("material", "wood");
		set("long", "这是一支木令牌，上面用朱漆写着一个「杀」字。\n");
		set("wield_msg", "$N抽出一支$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回怀里。\n");
	}
	init_blade(4);
	setup();
}
