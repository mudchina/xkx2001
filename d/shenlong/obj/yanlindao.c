//Cracked by Roath
// yanlingdao.c  雁翎刀
// ywz 09/10/96
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIW "雁翎刀" NOR, ({ "blade","dao" }));
	set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "柄");
		set("long", "这是一柄明晃晃的雁翎刀，江湖上的盗贼很喜欢用它。\n");
		set("value", 500);
                set("material", "steel");
		set("wield_msg", "$N「岑」的一声拔出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
        }
	init_blade(40);
        setup();
}
