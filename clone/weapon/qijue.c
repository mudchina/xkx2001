//Cracked by Roath
// weapon: xiuhua.c 绣花针
// Jay 4/7/96 unique weapon

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(HIY "七绝针" NOR, ({ "qijue zhen", "zhen", "needle" }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根黄金制成的针，镶在一个指环上。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N从口袋中拈出一根$n套在小手指上。\n");
		set("unwield_msg", "$N将手上的$n摘下来。\n");
	}
	init_sword(40);
	setup();
	::create();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int damage;

	if (victim->query_condition("snake_poison",1)< 50)
	{
		victim->apply_condition("snake_poison", 290);   
		return HIR "$n只觉得伤口上一麻！\n" NOR;
	}
}
