//Cracked by Roath
//七星剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIB"七星剑"NOR, ({ "qixing jian","sword","jian" }));
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("long", "这是一把寒光闪闪的宝剑，剑上纹有北斗七星图案。\n");
		set("value", 10000);
                set("material", "steel");
		set("wield_msg", "$N捏了一个剑诀，反手「唰」的一声拔出了$n。\n");
		set("unwield_msg", "$N将手中的$n插会剑鞘。\n");
        }
	init_sword(49);
        setup();
}
