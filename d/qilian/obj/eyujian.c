//Cracked by Roath
// Ryu, 12/16/96
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void init()
{
        add_action("do_cut", "cut");
	add_action("do_cut", "jian");
}

void create()
{
        set_name("鳄嘴剪", ({"ezui jian", "jian"}));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把尺许长的大剪刀，刀柄呈奇怪的弯曲状，刀口是一排铁齿，象鳄鱼的牙齿一样。\n");
                set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一把鳄鱼剪握在手中。\n");
                set("unwield_msg", "$N将手中的鳄鱼剪剪放下。\n");
        }
	init_blade(100);
	setup();
}

int do_cut(string arg)
{
        object target;
	object me = this_player();
	object weapon;
//        if( !target ) target = offensive_target(me);

	if (!arg)
        return notify_fail("你要剪什么？\n");

	target = present(arg,environment(me));

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("什麽？\n");

        if( !objectp(weapon = target->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip" )
                return notify_fail("什麽？\n");
	message_vision(HIW "$N举起手中鳄鱼剪往$n的" + weapon->name()
			+ "剪去。\n" NOR, me, target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
	message_vision(HIW "只听见「喀嚓」地一声，$n手中的" + weapon->name()
                                + "已经断为两截！\n" NOR, me, target);
                        weapon->unequip();
                        weapon->move(environment(target));
                        weapon->set("name", "断掉的" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        target->reset_action();
        } else {
        message_vision(HIW"可是$n看破了$N的意图，还招挡开。\n" NOR, me, target);
        }

        return 1;
}
