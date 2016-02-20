//Cracked by Roath
// dahuandao.c  大环刀
// ywz 09/10/96
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIW"大环刀"NOR, ({ "blade","dao" }));
	set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("long", "这是一把明晃晃的大环刀，刀背上还有几个圆环穿在上面，“哗棱棱”直响。\n");
		set("value", 1000);
                set("material", "steel");
		set("wield_msg", "$N「哗棱棱」的一声举起一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
        }
	init_blade(40);
        setup();
}
