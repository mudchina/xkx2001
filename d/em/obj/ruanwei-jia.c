//Cracked by Roath
// d/emei/obj/ruanwei-jia.c

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit ARMOR;

void create()
{
	set_name("软猬甲", ({ "ruanwei jia", "jia" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", 
"这是一件软猬甲。\n");
		set("material", "cloth");
		set("unit", "件");
		set("value", 7000000);
		set("wear_msg", HIY "$N穿上一件软猬甲。\n" NOR);
		set("unequip_msg", HIY "$N将软猬甲脱了下来。\n" NOR);
		set("armor_prop/armor", 250);
//		set("no_drop", 1);
	}
	setup();
	::create();
}

mixed hit_by(object me, object victim, int damage, object weapon)
{
	string result;
	if ( weapon )
		return damage/3;
	else {
		damage /= 2;
		if (damage > 0)
		    me->receive_wound("qi", damage/2, "被软猬甲刺死了");
		result = "只见$N大叫一声急忙收手，手上已被软猬甲刺得鲜血淋漓。\n";
		result+= "( $N"+ COMBAT_D->eff_status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
		return ([ "result": result, "damage": damage+random(damage) ]);
	}
}
		

			
