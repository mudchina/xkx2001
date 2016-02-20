//Cracked by Roath
// ningbi-jian 凝碧剑
// qfy September 29, 1996

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("凝碧剑",({ "ningbi jian", "ningbi", "sword", "jian" }) );
        set_weight(4000);
	set_color(HIG);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 7000);
                set("material", "steel");
                set("long", 
		"此剑为皇帝御赐，断金削铁，锋利异常。\n");
                set("wield_msg", 
		    HIG "$N抽出$n，只见此剑有如一泓清水，寒气逼人，大异寻常宝剑。\n" NOR );
                set("unwield_msg", HIG "$N潇洒地将$n一挥一旋，插回鞘中。\n" NOR);
                set("unequip_msg", HIG "$N潇洒地将$n一挥一旋，插回鞘中。\n" NOR);
        }
	init_sword(200);
        setup();
}
