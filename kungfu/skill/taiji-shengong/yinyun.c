//Cracked by Roath
// yinyun.c 「氤氲紫气」
// xQin 4/99

#include "poison_list.h"

int exert(object me, object target)
{
	string msg, msg1, msg2, poi_name, poison, poi_color, col_ansi;
	int i, tjsg_lvl, poi_lvl, neili_cost, tjsg_reg;
	object *inv, myarmor, urarmor;

	tjsg_lvl = (int)me->query_skill("taiji-shengong", 1);

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中运功疗毒。\n");

	if( !target || target == me )
	{
		for( i=0; i < sizeof(poison_list); i++ )
			if( me->query_condition(poison_list[i]["poison"]) > 0 )
			{
				poison = poison_list[i]["poison"];
				poi_name = poison_list[i]["name"];
				poi_color = poison_list[i]["color"];
				col_ansi = poison_list[i]["ansi"];
				poi_lvl = poison_list[i]["lvl"];
				break;
			}

		if( poi_lvl == 0 )
			return notify_fail("你并未中毒。\n");

		neili_cost = poi_lvl*100;
		tjsg_reg = 100+poi_lvl*10;

		if( (int)me->query("neili") < neili_cost+200 )
			return notify_fail("你现在的真气不足以鼓荡"MAG"「氤氲紫气」"NOR"。\n");

		if( tjsg_lvl < tjsg_reg )
			return notify_fail("你的"MAG"「氤氲紫气」"NOR"修为还不能化掉" + poi_name + "。\n");

		me->set("jiali", 0);
		message_vision("$N坐在一旁，慢慢以真气通走三关，鼓荡丹田中的"
		MAG"「氤氲紫气」"NOR"，将体内的" + col_ansi  + poi_name + NOR"一丝一丝的化掉。\n", me);

		me->start_busy(poi_lvl);
		call_out("huadu", poi_lvl, me, poi_name, poison, tjsg_lvl, poi_lvl, neili_cost);

		return 1;
	}
	else
	{
		if( me->query("gender") != "男性" )
			return notify_fail("你只能运用"MAG"「氤氲紫气」"NOR"为自己化毒。\n");

		if( !target->is_character() )
			return notify_fail("为" + target->name() + "疗毒？\n");

		if( target->query("gender") == "女性" )
		{
			if( target->is_spouse_of(me) )
			{
				inv = all_inventory(environment(me));
				for( i=0; i < sizeof(inv); i++ ) 
					if ( (string)inv[i]->query("race") == "人类"
					&& inv[i] != me && !me->is_spouse_of(inv[i]) )
						return notify_fail("众目睽睽之下脱光衣裳，你也不替你妻子想想？\n");
			}
			else
				return notify_fail("男女授受不亲，武当弟子行走江湖，於女色上人人律己严谨。\n");
		}

		for( i=0; i < sizeof(poison_list); i++ )
			if( me->query_condition(poison_list[i]["poison"]) > 0 )
				return notify_fail("你已身中" + poison_list[i]["name"] + 
				"，恐会散及" + target->name() + "。\n");

		for( i=0; i < sizeof(poison_list); i++ )
			if( target->query_condition(poison_list[i]["poison"]) > 0 )
				{
					poison = poison_list[i]["poison"];
					poi_name = poison_list[i]["name"];
					poi_color = poison_list[i]["color"];
					col_ansi = poison_list[i]["ansi"];
					poi_lvl = poison_list[i]["lvl"];
					break;
				}

		if( poi_lvl == 0 )
			return notify_fail(target->name() + "并未中毒。\n");

		if( target->is_fighting() )
			return notify_fail(target->name() + "正在战斗中，你无法为其疗毒。\n");

		if( target->is_busy() )
			return notify_fail(target->name() + "正忙着呢，你无法为其疗毒。\n");

		neili_cost = poi_lvl*200;
		tjsg_reg = 100+poi_lvl*15;

		if( tjsg_lvl < tjsg_reg )
			return notify_fail("你的"HIY"「纯阳无极功」"NOR"修为还不能为"
			 + target->name() + "吸取" + poi_name + "。\n");

		me->set("jiali", 0);
		msg = "$N手指连伸，点了$n身上"+ chinese_number(poi_lvl*3) +
		"处大穴。$p穴道被点，登时不再颤抖，脸上" + col_ansi + poi_color + NOR
		"气却愈来愈浓。\n";

		myarmor = me->query_temp("armor/cloth");
		urarmor = target->query_temp("armor/cloth");

		if( objectp(myarmor) )
		{
			msg1 = "自己也解开" + myarmor->name() + "，";
			myarmor->unequip();
		}
		else msg1 = "";

		if( objectp(urarmor) )
		{
			msg2 = "除去$n身上" + urarmor->name() + "，";
			urarmor->unequip();
		}
		else msg2 = "";

		msg += "$N当下" + msg2 + msg1 + "胸膛和$p的背心相贴。以"
		HIY"「纯阳无极功」"NOR"吸取$n身上的" + poi_name + "。\n";

		message_vision(msg, me, target);

		me->start_busy(poi_lvl);
		target->start_busy(poi_lvl);

		if( (int)me->query("neili") < neili_cost+200 )
			call_out("selfhurt", 1, me, target, neili_cost);
		else
			call_out("xidu", poi_lvl, me, target, poi_name, poison, poi_color, col_ansi, tjsg_lvl, poi_lvl, neili_cost);

		return 1;
	}
}

int huadu(object me, string poi_name, string poison, int tjsg_lvl, int poi_lvl, int neili_cost)
{
	int poi_amount, cure_amount, cure;

	if( !me || me->is_ghost() || !living(me) )
		return 0;

	poi_amount = (int)me->query_condition(poison, 1); // how deep I have got poisoned.
	cure_amount = (tjsg_lvl*tjsg_lvl)/(50*poi_lvl); // how deep the poison I can cure.
	cure = tjsg_lvl/poi_lvl*2/3; // once can cure how much.

	me->add("neili", -neili_cost);

	if( poi_amount > cure_amount ) // if I poisoned more than I can cure.
	{
		write("你体内" + poi_name + "胶固於经络百脉之中，无法化除。\n");
		return 0;
	}

	write("你将内力循环一周，身子如灌甘露，丹田里的真气似香烟缭绕，悠游自在。\n");

//	me->add("max_neili", -1);
	if( poi_amount < cure ) // if my poison less than once I can cure.
		me->apply_condition(poison, 0);
	else
		me->apply_condition(poison, poi_amount-cure);

	return 1;
}

int xidu(object me, object target, string poi_name, string poison, string poi_color, string col_ansi, int tjsg_lvl, int poi_lvl, int neili_cost)
{
	int my_poi, ur_poi, cure_amount, cure;

	if( !me || me->is_ghost() || !living(me) || !target || target->is_ghost() )
		return 0;

	my_poi = (int)me->query_condition(poison, 1); // my poisoned rate.
	ur_poi = (int)target->query_condition(poison, 1); // your poisoned rate.
	cure_amount = (tjsg_lvl*tjsg_lvl)/(33*poi_lvl); // the poisoned rate can be cure.
	cure = tjsg_lvl/poi_lvl*3/2; // once can cure how much.

	me->add("neili", -neili_cost);

	if( ur_poi > cure_amount ) // if your poisoned rate more than the rate I can cure.
	{
		write("你陡然发觉，不论自己如何摧动内力，" + target->name() + "身上的"
		+ poi_name + "却一丝也吸不出来。\n");
		return 0;
	}

	message_vision("过了约莫半个时辰，只见$N脸上隐隐现出"
	 + col_ansi + poi_color + NOR"气，手指微微颤动。\n", me);

	if( ur_poi < cure ) // if your poisoned rate less than once I can cure.
	{
		me->apply_condition(poison, my_poi+ur_poi);
		target->apply_condition(poison, 0);
	}
	else
	{
		me->apply_condition(poison, my_poi+cure);
		target->apply_condition(poison, ur_poi-cure);
	}

	return 1;
}

int selfhurt(object me, object target, int neili_cost)
{
	if( !me || me->is_ghost() || !living(me) || !target || target->is_ghost() )
		return 0;

	message_vision(HIW"$N将$n一抱入怀，立时大叫一声，全身打战。\n"NOR, me, target);
	if( me->query("neili") < neili_cost/2 )
	{
		me->set("neili", 0);
		me->receive_damage("qi", (int)me->query("qi")+1, "毒气攻心死了");
		return 1;
	}
	else
	{	
		me->add("neili", -(neili_cost/2));
		me->receive_damage("qi", neili_cost, "毒气攻心死了");
		me->receive_wound("qi", neili_cost/5, "毒气攻心死了");
		return 1;
	}
}

/*
待得他将寒气化尽，站起身来时，
*/
