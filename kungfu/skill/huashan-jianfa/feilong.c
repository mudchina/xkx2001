//Cracked by Roath
//feilong.c 天外飞龙

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	mapping prepare_status;
	string weapon, op_weapon, op_skill, *pname;
	int my_power, op_power, my_li, op_li, my_jing, my_nei, op_jing, op_nei;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("天外飞龙只能对战斗中的对手使用。\n");

	if( !me->query("huashan/feilong") )
		return notify_fail("天外飞龙乃是华山剑宗不传之密，你并未获得传授！\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
		return notify_fail("你所用的并非紫霞功，无法运劲施展天外飞龙！\n");

	if( me->query_skill("force") < 100 )
		return notify_fail("你的紫霞功火候未到，无法运劲施展天外飞龙！\n");

	if( me->query_skill("sword") < 150 )
		return notify_fail("你华山剑法修为不足，还不会使用天外飞龙！\n");

	if( me->query("neili") <= 400 )
		return notify_fail("你的内力不够使用天外飞龙！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用天外飞龙！\n");

	weapon = me->query_temp("weapon");

	if ( !objectp(op_weapon = target->query_temp("weapon")) ) {
		if ( mapp(prepare_status = target->query_skill_prepare()) ) {
                	pname  = keys(prepare_status);
			op_skill = pname[0];
		}
		else op_skill = "unarmed";
	}
	else {
		op_skill = op_weapon->query("skill_type");
	}

	my_jing = me->query("jingli") * 8 / 10;
	my_nei = me->query("neili") * 8 / 10;

	if ( target->query("neili") < me->query("neili") ) {
		op_nei = target->query("neili")*9/10;
	}
	else op_nei = my_nei;

	if ( target->query("jingli") < me->query("jingli") ) {
		op_jing = target->query("jingli")*9/10;
	}
	else op_jing = my_jing;

	message_vision(HIG "\n$N剑走龙蛇，白光如虹，凝重处如山岳巍峙，轻灵处若清风无迹，变幻莫测。\n"
			   "舞到急处，$N一声大喝，"+weapon->name()+"脱手飞出，化作一道惊虹射向$n！\n\n" NOR, me, target);
	tell_object(target, HIR "你只觉得敌招来势猛恶无伦，压得你透不过气来！\n" NOR);

	my_power = me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force")
		   + me->query_skill("parry") + me->query("combat_exp") / 1000;

	op_power = target->query_skill(op_skill) + target->query_skill("dodge") + target->query_skill("force")
		   + target->query_skill("parry") + target->query("combat_exp") / 1000;
		
	my_li = me->query("jingli") + me->query("neili");

	op_li = target->query("jingli") + target->query("neili");

	if ( random(my_power) > op_power/2 ) {

	   if ( random(my_li) > random(op_li) ) {
		if ( objectp(op_weapon) ) {
	   		message_vision(HIR "$N闪避不及，只好咬牙举起"+op_weapon->name()+"奋起全力强接攻势。\n" NOR, target);
			message_vision(HIR "硬砰之下，"+op_weapon->name()+"竟断为几截，但仍阻不了飞剑来势！\n" NOR, target);
			op_weapon->unequip();
			op_weapon->move(environment(me));
			op_weapon->set("name", "断掉的" + op_weapon->name());
	  		op_weapon->set("value", 0);
	  		op_weapon->set("weapon_prop", 0);
		}
	   	
		message_vision(HIR "$N避无可避，发出一声凄历的惨嚎，"+weapon->name()+"穿身而过！\n" NOR, target);
		weapon->move(target);
		target->receive_wound("qi", target->query("max_qi")*9/10, me);
//		target->die();
	   }
	   else if ( me->query_str() > target->query_str() ) {
		if ( objectp(op_weapon) ) {
			message_vision(HIR "硬砰之下，"+op_weapon->name()+"竟断为几截，终於抵消了飞剑来势！\n" NOR, target);
			message_vision("飞剑攻势受阻，力尽跌落。$N虽挡过一击，却也因精力内力钜耗，摇摇欲坠！\n", target);
			weapon->move(environment(me));
			op_weapon->unequip();
			op_weapon->move(environment(me));
			op_weapon->set("name", "断掉的" + op_weapon->name());
	  		op_weapon->set("value", 0);
	  		op_weapon->set("weapon_prop", 0);
	   	}
		else {
			message_vision(HIR "$N奋力闪躲，但却力有不逮，发出一声凄历的惨嚎，中剑重伤！\n" NOR, target);
			target->receive_wound("qi", target->query("max_qi")/2, me);
		}
	   }
	   else if ( random(2) == 1 && objectp(op_weapon) ) {
		message_vision(HIR "硬砰之下，$N的"+weapon->name()+"及$n的"+op_weapon->name()+"双双跌下！\n" NOR, me, target);
		weapon->move(environment(me));
		op_weapon->move(environment(me));
	   }
	   else if ( objectp(op_weapon) ) {
		message_vision(HIR "硬砰之下，$N的"+weapon->name()+"及$n的"+op_weapon->name()+"双双损毁！\n" NOR, me, target);
		op_weapon->unequip();
		op_weapon->move(environment(me));
		op_weapon->set("name", "断掉的" + op_weapon->name());
	  	op_weapon->set("value", 0);
	  	op_weapon->set("weapon_prop", 0);
		weapon->unequip();
		weapon->move(environment(me));
		weapon->set("name", "断掉的" + weapon->name());
	  	weapon->set("value", 0);
	  	weapon->set("weapon_prop", 0);
	   }
	   else {
		message_vision(HIR "$N奋力闪躲，但却力有不逮，发出一声凄历的惨嚎，中剑受伤！\n" NOR, target);
		target->receive_wound("qi", target->query("max_qi")/4, me);
	   }

	   target->add("jingli", -op_jing);
	   target->add("neili", -op_nei);
	}
	else {
//		weapon->move(environment(me));	
		message_vision(HIY "$N身形连闪，只守不攻，好不容易将此招避过，已吓得亡魂直冒！\n" NOR, target);
		message_vision(HIY "一击未中，"+weapon->name()+"嗖的一声又飞回$N手中。\n" NOR, me);
	}

	me->add("neili", -my_nei);
	me->add("jingli", -my_jing);
	target->start_busy(2);
	target->kill_ob(me);
	
	return 1;
}
