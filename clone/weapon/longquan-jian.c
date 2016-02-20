//Cracked by Roath
//龙泉剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIC"龙泉剑"NOR, ({ "longquan jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("long", "这把龙泉宝剑虽由后人仿制，远及不上上古神兵，但也是口利器。\n");
		set("value", 10000);
                set("material", "steel");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入剑鞘。\n");
        }
	init_sword(44);
        setup();
}
