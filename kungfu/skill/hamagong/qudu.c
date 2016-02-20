//Cracked by Roath
// qudu.c
//此法是倒运气息，须得头下脚上，气血逆行，毒气就会从进入身子之处回出。只是他新学乍练，每日只能逼出少许，须得一月以上，方能驱尽毒气。
//约莫一盏茶时分，手指上滴出几点黑血，胸臆间登觉大为舒畅。
//那少年极是聪明，一点便透，入耳即记，当下依法施为，果然麻木略减。他过了一阵气，双手手指尖流出几滴黑汁。

#include <ansi.h>

#include "/kungfu/skill/poison_list.h"

int exert(object me, object target)
{
	string poi_name, poison, poi_color, col_ansi;
	int i, hmg, poi_lvl, neili_cost, hmg_reg;

	hmg = (int)me->query_skill("hamagong", 1);

	if ((int)me->query_skill("hamagong") < 20 )
		return notify_fail("你的蛤蟆功修为还不够驱毒所需。\n");

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的内功修为不够逼毒所需。\n");

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中运功疗毒。\n");


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

		if(poison == "snake_poison" && hmg > 40)
			poi_lvl = 1;

		if(poison == "xx_poison" && hmg > 60)
			poi_lvl = 2;

		if(poison == "bt_poison" && hmg > 100)
			poi_lvl = 3;  //baituo highhand can cure his menpai's poison easier

		neili_cost = poi_lvl*100;
		hmg_reg = 10+poi_lvl*10;

		if(poi_lvl > 7 )
			return notify_fail(poi_name+"的毒性并非蛤蟆功所能驱除。\n");

		if( (int)me->query("neili") < neili_cost+100 )
			return notify_fail("你现在的内力不足以运使蛤蟆功逼出身上毒质。\n");

		if( hmg < hmg_reg )
			return notify_fail("你的蛤蟆功修为还不能化掉" + poi_name + "。\n");

		message_vision("$N头下脚上，倒运气息，气血逆行，想让"+poi_name+"从进入身子之处回出。\n", me);

		me->start_busy(poi_lvl);
		call_out("bidu", poi_lvl, me, poi_name, poison, hmg, poi_lvl, neili_cost);

		return 1;
}

int bidu(object me, string poi_name, string poison, int hmg, int poi_lvl, int neili_cost)
{
	int poi_amount, cure_amount, cure, plv;
	plv = (int)me->query_skill("poison", 1);

	if( !me || me->is_ghost() || !living(me) )
		return 0;

	poi_amount = (int)me->query_condition(poison, 1); // how deep I have got poisoned.
	cure_amount = (hmg*hmg)/(20*poi_lvl) + plv; // how deep the poison I can cure.
	cure = hmg/poi_lvl; // once can cure how much.

	me->add("neili", -neili_cost);

	if( poi_amount > cure_amount ) // if I poisoned more than I can cure.
	{
		write("你依法施为，但是体内"+poi_name+"太过厉害，中毒处麻木丝毫不减。\n");
		return 0;
	}
	message_vision("约莫一盏茶时分，$N手指上滴出几点黑血，胸臆间登觉大为舒畅。\n", me);

	if( poi_amount < cure ) // if my poison less than once I can cure.
		me->apply_condition(poison, 0);
	else
		me->apply_condition(poison, poi_amount-cure);

	return 1;
}
