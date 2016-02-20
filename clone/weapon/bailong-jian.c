//Cracked by Roath
//白龙剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(HIW"白龙剑"NOR, ({ "bailong jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("long", "这是一把寒气逼人的宝剑，剑刃较之一般长剑似乎要略长一些。\n");
		set("value", 1000);
                set("material", "steel");
		set("wield_msg","$N「铮」的一声清响，已拔出一把$n握在手中。\n");
		set("unwield_msg","$N将手中的$n「唰」的一声插回剑鞘。\n");
        }
	init_sword(45+random(11));
        setup();
	::create();
}
