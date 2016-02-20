//Cracked by Roath
// heji.c 《九阴真经》鞭法－「合击」
// xQin 8/99
/*
群雄昨日已见识了她软鞭的威力，不意她左手尚能同时用刀，
一长一短，一柔一刚，那是两般截然相异的兵刃。
*/

#include <ansi.h>

int perform(object me)
{
	object *inv, weapon1, weapon2;
	string short;
	int i;

	if( me->query_temp("secondary_weapon") )
		return notify_fail("你已经装备两把武器了。\n");

	inv = all_inventory(me);
	for( i=0; i < sizeof(inv); i++ )
	{
		short = inv[i]->query("id");
		if( (short == "bishou" || short == "duanjian" || short == "yuchang jian"
			|| inv[i]->query("name") == "短刀" || short == "yang dao")
			&& mapp(inv[i]->query("weapon_prop")) )
		{
			weapon2 = inv[i];
			break;
		}
	}

	if( (weapon1 = me->query_temp("weapon"))->query("skill_type") != "whip"
		|| !objectp(weapon2) )
		return notify_fail("你身上并无趁手的兵器，无法进行「合击」。\n");

	if( (int)me->query_skill("whip") < 350 )
		return notify_fail("你的鞭法不够娴熟，尚不能与其他武技进行「合击」。\n");

	message_vision(HIC"$N右手一抖，"+ weapon1->name() +
	HIC"登时卷成十多个大大小小的圈子，好看已极，左手翻处，青光闪动，露出了一"+ 
	weapon2->query("unit") + weapon2->name() +HIC"。\n"NOR, me);

	weapon2->set("flag", 2);
	weapon2->wield();
	weapon2->delete("flag");

	return 1;
}