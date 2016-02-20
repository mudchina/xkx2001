//Cracked by Roath
// d/taohua/obj/ruanwei-jia.c

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;

void create()
{
	set_name(YEL"软猬甲"NOR, ({ "ruanwei jia", "jia" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", MAG"这是一件黑黝黝的甲衣，看上去极轻极软，但却生满倒刺，刀剑不损，正是桃花岛镇岛之宝软猬甲。\n"NOR);
		set("material", "steel");
		set("unit", "件");
		set("value", 7000000);
		set("wear_msg", HIY "$N穿上一件软猬甲。\n" NOR);
		set("unequip_msg", HIY "$N将软猬甲脱了下来。\n" NOR);
		set("armor_prop/armor", 260);
		set("armor_prop/armor_vs_force", 200);
//		set("no_drop", 1);
	}
	setup();
	::create();
}

int is_special() { return 1;}

mixed hit_by(object me, object victim, int damage, object weapon)
{
	string result;
	if ( weapon )
		return damage*2/3;
	else {
		damage = damage/2;
		if (damage > 0)
		    me->receive_wound("qi", damage/4, victim);
		result = "只见$N大叫一声急忙收手，手上已被软猬甲刺得鲜血淋漓。\n";
		result+= "( $N"+ COMBAT_D->eff_status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
		return ([ "result": result, "damage": damage+random(damage) ]);
	}
}
		
