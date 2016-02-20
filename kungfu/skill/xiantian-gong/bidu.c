//Cracked by Roath
//bidu.c 全真教逼毒法门 
// changed by maco

#include "/kungfu/skill/poison_list.h"

int exert(object me, object target)
{
	string poi_name, poison, poi_color, col_ansi;
	int i, xtg, poi_lvl, neili_cost, xtg_reg;

	xtg = (int)me->query_skill("xiantian-gong", 1);

	if ((int)me->query_skill("xiantian-gong",1) < 100)
		return notify_fail("你的先天功修为还不够逼毒所需。\n");

	if( (int)me->query("max_neili") < 1000 )
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

		neili_cost = poi_lvl*100;
		xtg_reg = 100+poi_lvl*10;

		if( (int)me->query("neili") < neili_cost+200 )
			return notify_fail("你现在的内力不足以运使先天功逼出身上毒质。\n");

		if( xtg < xtg_reg )
			return notify_fail("你的先天功修为还不能化掉" + poi_name + "。\n");

		me->set("jiali", 0);
		//$N跨入水缸内，清水直浸到头颈。
		//只见王处一闭目而坐，急呼缓吸，过了一顿饭工夫，一缸清水竟渐渐变成黑色，他脸色却也略复红润。
		message_vision("$N盘膝坐下，运起先天功，以内力阻住" + col_ansi  + poi_name + NOR"上行，头上一缕缕热气袅袅而上，犹如蒸笼一般。\n", me);

		me->start_busy(poi_lvl);
		call_out("bidu", poi_lvl, me, poi_name, poison, xtg, poi_lvl, neili_cost);

		return 1;
}

int bidu(object me, string poi_name, string poison, int xtg, int poi_lvl, int neili_cost)
{
	int poi_amount, cure_amount, cure;

	if( !me || me->is_ghost() || !living(me) )
		return 0;

	poi_amount = (int)me->query_condition(poison, 1); // how deep I have got poisoned.
	cure_amount = (xtg*xtg)/(50*poi_lvl); // how deep the poison I can cure.
	cure = xtg/poi_lvl; // once can cure how much.

	me->add("neili", -neili_cost);

	if( poi_amount > cure_amount ) // if I poisoned more than I can cure.
	{
		write("你运功一阵，祗感神困力疲，没料到体内" + poi_name + "如此厉害，竟然驱之不出。\n");
		return 0;
	}
	message_vision("$N闭目而坐，急呼缓吸，过了一顿饭工夫，脸色略复红润。\n", me);
//王处一道：“扶我出来，换一缸清水。”郭靖依然换了水，又将他放入缸内。这时才知他是以内功逼出身上毒质，化在水里。这般连换了四缸清水。水中才无黑色。王处一笑道：“没事啦。”扶着缸沿，跨了出来
//	me->add("max_neili", -1);
	if( poi_amount < cure ) // if my poison less than once I can cure.
		me->apply_condition(poison, 0);
	else
		me->apply_condition(poison, poi_amount-cure);

	return 1;
}
