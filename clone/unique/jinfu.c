//Cracked by Roath

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit AXE;
#include "/clone/unique/special_weapon.h"

void create()
{
        set_name(HIY"黄金斧"NOR, ({ "huangjin fu", "fu", "axe" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把沉重的长柄金斧，是古西域暴君桑拉巴使用的兵器，完全是黄金打造的。\n");
                set("value", 50000);
                set("material", "gold");
                set("wield_msg", "$N劲贯双臂，举起了一把$n。\n");
                set("unwield_msg", "$N放下了手中的$n。\n");
        }
        init_axe(140);
	setup();
	::create();
}
