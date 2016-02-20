//Cracked by Roath
//碧水剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIG"碧水剑"NOR, ({ "bishui jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("long", "这是一柄亮如秋水的宝剑，看来是一口断金削铁的利器。\n");
		set("value", 10000);
                set("material", "steel");
		set("wield_msg", "$N轻轻一笑，抽出$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
	init_sword(45+random(11));
        setup();
	::create();
}
