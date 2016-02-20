//Cracked by Roath
// fumo-dao.c 伏魔刀

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;

void create()
{
	set_name("伏魔刀", ({ "fumo dao", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把银光雪亮的伏魔刀，刀刃间隐隐有血光流动，锋利无匹，
映面生寒。此刀数百年前由达摩老祖携入中原，一路用之除妖灭魔，
乃是佛家无上降魔法宝。\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 100000);
		set("wield_msg", HIY "只听「铮」的一声，伏魔刀脱鞘飞出，自行跃入$N掌中。
瞬时天际间风云变色，电闪雷鸣，弥漫着一片无边杀意。\n" NOR);
		set("unwield_msg", HIY "伏魔刀自$N掌中飞起，在半空中一转，「唰」地跃入刀鞘。\n" NOR);
		set("clone_ob", "/clone/weapon/fumo-dao");
		set("shaolin", 1);
	}
	init_blade(270);
	setup();
	::create();
}
